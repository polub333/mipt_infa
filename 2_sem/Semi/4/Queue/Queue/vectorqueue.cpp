#include "vectorqueue.h"

VectorQueue::VectorQueue()
{

}

VectorQueue::VectorQueue(u64 n)
{
    head.Realloc(n);
}

void VectorQueue::PushBack(i64 elem)
{
    head.PushBack(elem);
}

i64 VectorQueue::PopFront()
{
    if(tail.Size() == 0){
        MoveHeadToTail();
    }
    i64 elem = tail[tail.Size() - 1];
    tail.PopBack();
    return elem;
}

void VectorQueue::MoveHeadToTail()
{
    u64 hSize = head.Size();
    tail.Realloc(hSize);
    for(u64 i = 0; i < hSize; ++i){
        //tail[i] = head[head.Size() - 1];
        tail.PushBack(head[head.Size() - 1]);
        head.PopBack();
    }
}
