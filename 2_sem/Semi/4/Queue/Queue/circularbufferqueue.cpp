#include "circularbufferqueue.h"

CircularBufferQueue::CircularBufferQueue()
{
    data.Resize(1);
    head = 0;
    tail = 0;
}

CircularBufferQueue::CircularBufferQueue(u64 n)
{
    data.Resize(n);
    head = 0;
    tail = 0;
}

void CircularBufferQueue::PushBack(i64 elem)
{

    data[tail] = elem;
    tail = (tail + 1) % data.Size();
    if (tail == head){
        Realloc();
    }
}

i64 CircularBufferQueue::PopFront()
{
    i64 elem = data[head];
    head = (head + 1) % data.Size();
    return elem;
}

void CircularBufferQueue::Realloc()
{
    u64 oldSize = data.Size();
    data.Resize(2*data.Size());
    i64* newData = new i64[data.Size()];
    for (u64 i = 0; i < oldSize; ++i){
        newData[i] = data[(head + i) % oldSize];
    }
    for (u64 i = 0; i < oldSize; ++i){
        data[i] = newData[i];
    }
    delete[] newData;
    tail = oldSize;
    head = 0;
}

void CircularBufferQueue::Clear()
{
    data.Clear();
    data.Resize(1);
    head = 0;
    tail = 0;
}
