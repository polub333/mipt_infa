#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdint>

using Data = int64_t;

struct ListItem
{
    Data data;
    ListItem* prev;
    ListItem* next;
};

struct List
{
    List();
    ListItem* head;
    ListItem* tail;
    ~List();
    void pushBack(Data d);
    void pushFront(Data d);
    void popBack();
    void popFront();
    void show();
};

#endif // LINKEDLIST_H
