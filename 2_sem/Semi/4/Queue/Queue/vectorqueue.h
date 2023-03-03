#ifndef VECTORQUEUE_H
#define VECTORQUEUE_H

#include <cstdint>
#include "vector.h"

using u64 = uint64_t;
using i64 = int64_t;

class VectorQueue
{
public:
    VectorQueue();
    VectorQueue(u64 n);

    void PushBack(i64 elem);
    i64 PopFront();
private:
    void MoveHeadToTail();
    Vector head;
    Vector tail;
};

#endif // VECTORQUEUE_H
