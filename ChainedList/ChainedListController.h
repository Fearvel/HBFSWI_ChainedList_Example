//
// Created by schreiner.andreas on 12.09.2018.
//

#ifndef CHAINEDLIST_CHAINEDLISTCONTROLLER_H
#define CHAINEDLIST_CHAINEDLISTCONTROLLER_H

#include "ChainedListItem/ChainedListItem.h"
#include "Exceptions/ChainedListExceptions.h"

enum ChainedListType {
    SingleChain, DoubleChain
};

class ChainedListController {
private:
    ChainedListItem *_root = NULL;
    int _itemCount = 0;

    void DeleteItem(ChainedListItem *itm, string s);

    bool ObjectExists(ChainedListItem *itm, string s);

    void AddSortedListItem(ChainedListItem *itm, ChainedListItem *insertItm);

    ChainedListItem *GetLastItem(ChainedListItem *itm);

    void SortList(ChainedListItem *i);

    void SortList(ChainedListItem *i, ChainedListItem *j);

public:
    enum Auswahl {
        Exit = 0, Add, AddSorted, Sort, Del, CType
    };


    ChainedListController();

    ~ChainedListController();

    int Count();

    void AddListItem(string s);

    void AddSortedListItem(string s);

    ChainedListItem *GetFirstItem();

    void DeleteItem(string s);

    void SortList();
};


#endif //CHAINEDLIST_CHAINEDLISTCONTROLLER_H
