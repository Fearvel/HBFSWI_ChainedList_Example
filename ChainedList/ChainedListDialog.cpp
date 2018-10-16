//
// Created by schreiner.andreas on 13.09.2018.
//
#include "ChainedListDialog.h"

ChainedListDialog::ChainedListDialog(ChainedListType c) {
    _chainedListType = c;
    _outputLineManager = new OutputLineManager();
}

ChainedListDialog::~ChainedListDialog() {
    delete (_clc);
    delete (_outputLineManager);
}

void ChainedListDialog::DrawBox(string s) {
    if (s.length() > 60)
        throw InvalidInputException("Too Long");

    string buffer[5];
    for (int j = 0; j < 5; ++j) {
        buffer[j] = "";
    }
    for (int i = 0; i < s.length() + 4; ++i) {
        buffer[0] += GetBottomHalfBlock();
        buffer[4] += GetTopHalfBlock();
        if (i == 0 || i == s.length() + 3) {
            buffer[1] += GetVerticalBlock();
            buffer[2] += GetVerticalBlock();
            buffer[3] += GetVerticalBlock();
        } else if (i == 1 || i == s.length() + 2) {
            buffer[1] += " ";
            buffer[2] += " ";
            buffer[3] += " ";
        } else {
            buffer[1] += " ";
            buffer[3] += " ";
            if (i == 2) {
                buffer[2] += s;
            }
        }
    }
    for (int k = 0; k < 5; ++k) {
        _outputLineManager->GetOutputLine(s.length())->Lines[k] += buffer[k];
    }
}

void ChainedListDialog::DrawArrows() {
    if (_chainedListType == SingleChain) {
        _outputLineManager->Append(_singleChain,4);
    } else {
        _outputLineManager->Append(_doubleChain,4);
    }
}

void ChainedListDialog::DrawNullNext() {
    _outputLineManager->Append( _nullNext,0);
}

void ChainedListDialog::DrawNullPrev() {
    if (_chainedListType == SingleChain)
        return;
    string  *n = _nullPrev;
    _outputLineManager->Append( _nullPrev,8);
}

void ChainedListDialog::OutputLines() {
    _outputLineManager->PrintOutputLines();
}

void ChainedListDialog::PrintMenu() {
    cout << "\n";
    cout << "Itemcount: " << _clc->Count() << "\n" << "Max screen width: " << _outputLineManager->MaxTerminalWidth
         << "\n\n";

    cout << "(1) Add\n(2) Delete\n(3) ";
    if (_chainedListType == SingleChain) {
        cout << "Swap to double Chained List display\n";
    } else {
        cout << "Swap to single Chained List display\n";
    }
    cout << "(4) Change max screen width\n(0) Exit\n\n" << "Your choice: ";
}

void ChainedListDialog::OpenDialog() {
    int input = 99;
    while (input != 0) {
        ClearShell();
        DrawList();
        OutputLines();
        PrintMenu();
        try {
            cin >> input;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                input = 99;
                throw InvalidInputException("Please enter a Number between 0 inclusive and 2 inclusive");
            } else {
                switch (input) {
//                    case 1: {
//                        string name;
//                        cout << "Name: ";
//                        cin >> name;
//                        _clc->AddListItem(name);
//                        break;
//                    }
                    case 1:{

                        string name;
                        cout << "Name: ";
                        cin >> name;
                        _clc->AddSortedListItem(name);

                        break;
                    }
//                    case 3:{
//                        _clc->SortList();
//                        break;
//                    }
                    case 2: {
                        string name;
                        cout << "Name: ";
                        cin >> name;
                        _clc->DeleteItem(name);
                        break;
                    }
                    case 3: {
                        if (_chainedListType == SingleChain) {
                            _chainedListType = DoubleChain;
                        } else {
                            _chainedListType = SingleChain;
                        }
                        break;
                    }
                    case 4: {
                        cout << "Width: ";
                        cin >> _outputLineManager->MaxTerminalWidth;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore();
                            _outputLineManager->MaxTerminalWidth = 100;
                            throw InvalidInputException("The Width needs to be a Number");
                        }
                        break;
                    }
                    case 0:
                        break;
                    default:
                        throw InvalidInputException("Please enter a Number between 0 inclusive and 2 inclusive");
                        break;
                }
            }
        } catch (InvalidInputException &e) {
            PrintError(e.what());
        } catch (ObjectNotExistingException e) {
            PrintError(e.what());
        } catch (ObjectExistsException e) {
            PrintError(e.what());
        }

    }
    ClearShell();
}


void ChainedListDialog::DrawList() {
    ClearLines();
    DrawNullPrev();
    DrawList(_clc->GetFirstItem());


}

void ChainedListDialog::DrawList(ChainedListItem *itm) {
    if (itm != NULL) {
        DrawBox(itm->Content);
        if (itm->Next == NULL) {
            DrawNullNext();
        } else {
            DrawArrows();
            DrawList(itm->Next);
        }
    }

}

void ChainedListDialog::ClearLines() {
    for (int i = 0; i < 5; ++i) {
        _outputLineManager->Clear();
    }
}

void ChainedListDialog::PrintError(string s) {
    ClearShell();
    cout << "An error occurred!!\n" << s << "\nPlease press Enter to continue\n";
    cin.clear();
    fflush(stdin);
    WaitForEnter();
}


OutputLine *ChainedListDialog::GetOutputLine(int size) {
return NULL;
}

void ChainedListDialog::ClearShell() {
#ifdef _WIN32
    system("cls");
#else
    // Assume POSIX
    system("clear");
#endif
}

char ChainedListDialog::GetVerticalBlock() {
#ifdef _WIN32
    return _verticalBlockWin;
#else
    return  _verticalBlock;
#endif
}

char ChainedListDialog::GetTopHalfBlock() {
#ifdef _WIN32
    return _topHalfBlockWin;
#else
    return  _lineBlock;
#endif
}

char ChainedListDialog::GetBottomHalfBlock() {
#ifdef _WIN32
    return _bottomHalfBlockWin;
#else
    return  _lineBlock;
#endif
}

void ChainedListDialog::WaitForEnter() {
#ifdef _WIN32
    getchar();
#else
    cin.ignore();
    cin.ignore();
#endif
}



