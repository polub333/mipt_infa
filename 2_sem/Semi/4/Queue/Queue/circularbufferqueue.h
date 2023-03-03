#ifndef CIRCULARBUFFERQUEUE_H
#define CIRCULARBUFFERQUEUE_H

#include <cstdint>
#include "vector.h"

using u64 = uint64_t;
using i64 = int64_t;

class CircularBufferQueue
{
public:
    CircularBufferQueue();
    CircularBufferQueue(u64 n);

    void PushBack(i64 elem);
    i64 PopFront();
private:
    void Realloc();
    Vector data;
    u64 head;
    u64 tail;
};

#endif // CIRCULARBUFFERQUEUE_H
