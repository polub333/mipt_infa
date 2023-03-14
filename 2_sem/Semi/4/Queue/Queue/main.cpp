#include <iostream>

using namespace std;

#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

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

template <typename Q>
void calculateTime(Q q, std::string queueType)
{
    const u64 N = 1.5e5;
    const u64 attemptsNumber = 100;
    fstream f(queueType + ".txt", std::ios_base::out);
    for(u64 size = 0; size <= N; size += 2048){
        double totalTimeAddition = 0;
        double totalTimeDeletion = 0;
        for(u64 attempt = 0; attempt < attemptsNumber; ++attempt){
            q.Clear();
            auto begin = std::chrono::steady_clock::now();
            for(u64 i = 0; i < size; ++i){
                q.PushBack(i*attempt);
            }

            auto intermediate = std::chrono::steady_clock::now();
            for(u64 i = 0; i < size; ++i){
                q.PopFront();
            }
            auto end = std::chrono::steady_clock::now();
            totalTimeAddition += (intermediate - begin).count();
            totalTimeDeletion += (end - intermediate).count();
        }
        double timeAddition = totalTimeAddition / attemptsNumber;
        double timeDeletion = totalTimeDeletion / attemptsNumber;
        f << size << " " << std::fixed << std::setprecision(15)
          << timeAddition << " " << timeDeletion << std::endl;
    }
    f.close();
}

int main()
{
    VectorQueue vq;
    ListQueue lq;
    CircularBufferQueue cbq;
    calculateTime(vq, "vector_queue");
    calculateTime(lq, "list_queue");
    calculateTime(cbq, "circular_buffer_queue");

    return 0;
}
