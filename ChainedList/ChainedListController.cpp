//
// Created by schreiner.andreas on 12.09.2018.
//

#include "ChainedListController.h"

ChainedListController::ChainedListController() {}

ChainedListController::~ChainedListController() {
    delete (_root);
}

ChainedListItem *ChainedListController::GetFirstItem() {
    return _root;
}

ChainedListItem *ChainedListController::GetLastItem(ChainedListItem *itm) {
    if (itm->Next == NULL) {
        return itm;
    } else {
        return GetLastItem(itm->Next);
    }
}

int ChainedListController::Count() {
    int count  = 0;
    ChainedListItem *itm = _root;
    if(_root != NULL) {
        count++;
        while (itm->Next != NULL) {
            count++;
            itm = itm->Next;
        }
    }
    return count;
}

void ChainedListController::AddListItem(string s) {
    ChainedListItem *itm = new ChainedListItem(s);
    if (ObjectExists(_root, s)) {
        throw ObjectExistsException("OBJ: " + s + " already Exists");
    }
    if (_root == NULL) {
        _root = itm;
    } else {
        ChainedListItem *lastItem = GetLastItem(_root);
        itm->Prev = lastItem;
        lastItem->Next = itm;
    }
    _itemCount++;
}

bool ChainedListController::ObjectExists(ChainedListItem *itm, string s) {
    if (itm == NULL || itm->Next == NULL && itm->Content.compare(s) != 0) {
        return false;
    } else if (itm->Content.compare(s) == 0) {
        return true;
    } else {
        return ObjectExists(itm->Next, s);
    }
}

void ChainedListController::DeleteItem(string s) {
    ChainedListItem *deletableObject;
    if (_root != NULL) {
        if (_root->Content.compare(s) != 0) {
            DeleteItem(_root, s);
        } else {
            deletableObject = _root;
            if (_root->Next == NULL) {
                _root = NULL;
            } else {
                _root = _root->Next;
                _root->Prev = NULL;
            }
            deletableObject->Next =NULL;
            delete (deletableObject);
            _itemCount--;
        }
    } else {
        throw ObjectNotExistingException(s + "does not exist");
    }
}

void ChainedListController::DeleteItem(ChainedListItem *itm, string s) {
    ChainedListItem *deletableObject;
    if (itm->Next != NULL && itm->Next->Content == s) {
        deletableObject = itm->Next;
        if (itm->Next->Next != NULL) {
            itm->Next->Next->Prev = itm;
            itm->Next = itm->Next->Next;
            deletableObject->Prev = NULL;
            deletableObject->Next = NULL;
        } else {
            itm->Next = NULL;
        }
        delete deletableObject;
        return;
    } else if (itm->Next->Next != NULL) {
        DeleteItem(itm->Next, s);
    } else {
        throw ObjectNotExistingException(s + "does not exist");
    }
    _itemCount--;
}

void ChainedListController::AddSortedListItem(string s) {
    ChainedListItem *itm = new ChainedListItem(s);
    if (ObjectExists(_root, s)) {
        throw ObjectExistsException("OBJ: " + s + " already Exists");
    }
    if (_root == NULL) {
        _root = itm;
    } else {
        if (_root->Content.compare(s) > 0) {
            itm->Next = _root;
            _root->Prev = itm;
            _root = itm;
        } else {
            AddSortedListItem(_root, itm);
        }
    }
    _itemCount++;

}

void ChainedListController::AddSortedListItem(ChainedListItem *itm, ChainedListItem *insertItm) {
    if (itm->Content.compare(insertItm->Content) < 0) {
        if (itm->Next != NULL) {
            if (itm->Next->Content.compare(insertItm->Content) > 0) {
                insertItm->Next = itm->Next;
                insertItm->Prev = itm->Next->Prev;
                itm->Next->Prev = insertItm;
                if(insertItm->Prev != NULL) {
                    insertItm->Prev->Next = insertItm;
                }
            } else {

                AddSortedListItem(itm->Next, insertItm);
            }
        } else {
            itm->Next = insertItm;
            insertItm->Prev = itm;
        }
    }
}

void ChainedListController::SortList() {//BUGGY
    SortList(_root);
}

void ChainedListController::SortList(ChainedListItem *i) {
    if(i != NULL) {
        ChainedListItem *end = GetLastItem(i);
        if (i != end) {
            if (i->Next != NULL) {
                ChainedListItem *iN = i->Next;

                SortList(i, end);
                SortList(iN);
            }
        }
    } else{
        throw ObjectNotExistingException("Liste Leer");
    }
}

void ChainedListController::SortList(ChainedListItem *i, ChainedListItem *j) {
    if (i != j) {
        if (i->Content.compare(j->Content) > 0) {
            ChainedListItem *iN = i->Next;
            ChainedListItem *iP = i->Prev;
            if (i->Prev != NULL) {
                i->Prev->Next = j;
            } else{
                _root = j;
            }
            i->Prev = j->Prev;
            if (i->Next != NULL) {
                i->Next->Prev = j;
            }
            i->Next = j->Next;
            if (j->Prev != NULL) {
                j->Prev->Next = i;
            }
            j->Prev = iP;
            if (j->Next != NULL) {
                j->Next->Prev = i;
            }
            j->Next = iN;
            if (i->Prev != NULL) {
                SortList(j, i->Prev);
            }
        } else {
            if (j->Prev != NULL) {
                SortList(i, j->Prev);
            }
        }
    }
}





