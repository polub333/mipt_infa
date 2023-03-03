#include "list.h"

List::List()
{
    head = nullptr;
    tail = nullptr;
}

List::~List()
{
    if((head == nullptr) && (tail == nullptr))
        return;
    ListItem* cur = head;
    while(cur != nullptr){
        head = cur->next;
        delete cur;
        cur = head;
    }
}

void List::PushBack(Data d)
{
    ListItem* itm = new ListItem;
    itm->data = d;
    itm->prev = tail;

    if(head == nullptr && tail == nullptr){
        head = itm;
        tail = itm;
        itm->next = nullptr;
    }

    tail->next = itm;
    itm->next = nullptr;
    tail = itm;
}

void List::PopFront()
{
    if((head == nullptr) && (tail == nullptr)){
        return;
    }
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
}

Data List::front()
{
    return head->data;
}
