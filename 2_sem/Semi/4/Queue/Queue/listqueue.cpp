#include "listqueue.h"

ListQueue::ListQueue()
{

}

ListQueue::ListQueue(u64 n)
{
    //data.resize(n);
}

void ListQueue::PushBack(i64 elem)
{
    data.PushBack(elem);
}

i64 ListQueue::PopFront()
{
    i64 elem = data.front();
    data.PopFront();
    return elem;
}

void ListQueue::Clear()
{
    data.Clear();
}
