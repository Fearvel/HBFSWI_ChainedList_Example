//
// Created by schreiner.andreas on 13.09.2018.
//

#ifndef CHAINEDLIST_CHAINEDLISTDIALOG_H
#define CHAINEDLIST_CHAINEDLISTDIALOG_H

#include <iostream>
#include "ChainedListController.h"
#include "OutputLineManager.h"

using namespace std;


class ChainedListDialog {
private:
    ChainedListType _chainedListType;
    ChainedListController *_clc = new ChainedListController();
    OutputLineManager *_outputLineManager;
    char _verticalBlockWin = (char) 219;
    char _topHalfBlockWin = (char) 223;
    char _bottomHalfBlockWin = (char) 220;
    char _verticalBlock = '|';
    char _lineBlock = '-';
    string _nullPrev[5] = {"        ", "NULL <- ", "        ", "        ", "        "};
    string _nullNext[5] = {"        ", "        ", "        ", " -> NULL", "        "};
    string _singleChain[5] = {"    ", "    ", "    ", " -> ", "    "};
    string _doubleChain[5] = {"    ", " <- ", "    ", " -> ", "    "};


    char GetVerticalBlock();

    char GetTopHalfBlock();

    char GetBottomHalfBlock();

    OutputLine *GetOutputLine(int size);

    void DrawList(ChainedListItem *itm);

    void ClearLines();

    void DrawBox(string s);

    void DrawArrows();

    void DrawNullPrev();

    void DrawNullNext();

    void OutputLines();

    void PrintMenu();

    void DrawList();

    void PrintError(string s);

    void ClearShell();
    void WaitForEnter();

public:
    ChainedListDialog(ChainedListType c);

    ~ChainedListDialog();

    void OpenDialog();

};


#endif //CHAINEDLIST_CHAINEDLISTDIALOG_H
