#ifndef LIST_H
#define LIST_H

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
    void PushBack(Data d);
    void PushFront(Data d);
    void PopBack();
    void PopFront();
    Data front();
    void Clear();
};

#endif // LIST_H
