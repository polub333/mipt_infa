#include "linkedlist.h"

int main()
{
    List list;
    list.pushBack(15);
    list.pushBack(1);
    list.pushBack(2);
    list.popFront();
    list.pushBack(4);
    list.show();
    return 0;
}
