//
// Created by schreiner.andreas on 13.09.2018.
//

#ifndef CHAINEDLIST_OUTPUTLINE_H
#define CHAINEDLIST_OUTPUTLINE_H

#include <iostream>

using namespace std;

class OutputLine {
public:
    OutputLine * Next = NULL;
    bool Full = false;
    string Lines[5];

    OutputLine() {
        Clear();
    }
    ~OutputLine(){
        if (Next != NULL){
            OutputLine * deletableObject = Next;
            Next = NULL;
            delete(deletableObject);
        }
    }

    void Clear() {
        for (int i = 0; i < 5; ++i) {
            Lines[i] = "";
        }
    }

    void Print() {
        for (int i = 0; i < 5; ++i) {
            cout << Lines[i] + "\n";
        }
    }

};

#endif //CHAINEDLIST_OUTPUTLINE_H
