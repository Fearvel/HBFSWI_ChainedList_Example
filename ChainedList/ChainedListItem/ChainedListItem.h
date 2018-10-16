//
// Created by schreiner.andreas on 12.09.2018.
//

#ifndef CHAINEDLIST_CHAINEDLISTITEM_H
#define CHAINEDLIST_CHAINEDLISTITEM_H

#include <stddef.h>
#include <iostream>

using namespace std;

class ChainedListItem {
public:
    ChainedListItem *Prev = NULL;
    ChainedListItem *Next = NULL;
    string Content;

    ChainedListItem(string content) {
        Content = content;
    }

    ~ChainedListItem() {
        if (Next != NULL){
            ChainedListItem * deletableObject = Next ;
            Next->Prev = NULL;
            Next = NULL;
            delete(deletableObject);
        }
    }


};

#endif //CHAINEDLIST_CHAINEDLISTITEM_H
