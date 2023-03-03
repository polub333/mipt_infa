#include <iostream>

using namespace std;

#include <iostream>
#include "vector.h"
#include "vectorqueue.h"
#include "listqueue.h"
#include "circularbufferqueue.h"

template<typename Q>
bool check(Q q)
{
    bool correct = true;
    for (u64 i = 0; i < 12; ++i){
        q.PushBack(i*i);
    }
    for (u64 i = 0; i < 12; ++i){
        if(q.PopFront() != i*i)
            correct = false;
    }
    for (u64 i = 0; i < 100; ++i){
        q.PushBack(i*i*i + 100);
    }
    for (u64 i = 0; i < 100; ++i){
        if(q.PopFront() != i*i*i + 100)
            correct = false;
    }
    for (u64 i = 0; i < 5; ++i){
        q.PushBack(i + 1);
    }
    for (u64 i = 0; i < 5; ++i){
        if(q.PopFront() != i + 1)
            correct = false;
    }
    return correct;
}

int main()
{
    VectorQueue vq;
    ListQueue lq;
    CircularBufferQueue cbq;
    std::cout << "Vector queue: " << check(vq) << std::endl
              << "List queue: " << check(lq) << std::endl
              << "Circular buffer queue: " << check(cbq) <<std::endl;
    return 0;
}
