#include <iostream>
#include "ChainedList/ChainedListDialog.h"

using namespace std;

int main() {
    ChainedListDialog *cld = new ChainedListDialog(SingleChain);
    cld->OpenDialog();
    return 0;
}