//
// Created by schreiner.andreas on 13.09.2018.
//

#ifndef CHAINEDLIST_OUTPUTLINEMANAGAER_H
#define CHAINEDLIST_OUTPUTLINEMANAGAER_H

#include "OutputLine.h"

class OutputLineManager {
public:
    OutputLine *_root;

    int MaxTerminalWidth = 100;

    OutputLine *GetOutputLine(int sizeToAdd) {
        return GetOutputLine(_root, sizeToAdd);
    }

    OutputLine *GetOutputLine() {
        return GetOutputLine(_root);
    }

    OutputLineManager() {
        _root = new OutputLine();
    }

    ~OutputLineManager() {
        delete (_root);
    }

    OutputLine *GetOutputLine(OutputLine *ol, int sizeToAdd) {
        if (ol->Full || ol->Lines[4].length() + sizeToAdd >= MaxTerminalWidth -8) {
            ol->Full = true;
            if (ol->Next == NULL) {
                ol->Next = new OutputLine();
                return ol->Next;
            }
            GetOutputLine(ol->Next, sizeToAdd);
        } else {
            return ol;
        }
    }

    OutputLine *GetOutputLine(OutputLine *ol) {
        if (ol->Next != NULL) {
            return GetOutputLine(ol->Next);
        } else {
            return ol;
        }
    }

    void PrintOutputLines() {
        if (_root != NULL) {
            cout << _root->Lines[0] + "\n" + _root->Lines[1] + "\n" + _root->Lines[2] + "\n"
                    + _root->Lines[3] + "\n" + _root->Lines[4] + "\n\n";
            if (_root->Next != NULL) {
                PrintOutputLines(_root->Next);
            }
        }
    }

    void PrintOutputLines(OutputLine *ol) {
        cout << ol->Lines[0] + "\n" + ol->Lines[1] + "\n" + ol->Lines[2] + "\n"
                + ol->Lines[3] + "\n" + ol->Lines[4] + "\n\n";
        if (ol->Next != NULL) {
            PrintOutputLines(ol->Next);
        }
    }

    void Clear() {
        for (int i = 0; i < 5; ++i) {
            _root->Lines[i] = "";
        }
        _root->Full = false;
        if (_root->Next != NULL) {
            OutputLine *deletableObject = _root->Next;
            Clear(_root->Next);
            _root->Next = NULL;
            delete (deletableObject);
        }
    }

    void Clear(OutputLine *ol) {
        if (ol->Next != NULL) {
            OutputLine *deletableObject = ol->Next;
            Clear(ol->Next);
            ol->Next = NULL;
            delete (deletableObject);
        }
    }

    void Append(string (&s)[5], int lenght) {
        if (lenght > 0) {
            for (int i = 0; i < 5; ++i) {
                GetOutputLine(lenght)->Lines[i] += s[i];
            }
        } else{
            for (int i = 0; i < 5; ++i) {
                GetOutputLine()->Lines[i] += s[i];
            }
        }
    }

};


#endif //CHAINEDLIST_OUTPUTLINEMANAGAER_H
