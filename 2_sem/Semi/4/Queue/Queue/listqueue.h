#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include <list>
#include <cstdint>
#include "list.h"

using u64 = uint64_t;
using i64 = int64_t;

class ListQueue
{
public:
    ListQueue();
    ListQueue(u64 n);
    void PushBack(i64 elem);
    i64 PopFront();
    void Clear();
private:
    List data;
};

#endif // LISTQUEUE_H
