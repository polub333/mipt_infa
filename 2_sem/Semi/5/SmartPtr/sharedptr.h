#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <cstdint>
#include <algorithm>

using u64 = uint64_t;

class CounterBlock
{
public:
    CounterBlock() : sharedCounter(0), weakCounter(0) {}
    u64 sharedCounter;
    u64 weakCounter;
};

template <typename T>
class WeakPtr;

template <typename T>
class SharedPtr
{
    friend class WeakPtr<T>;
public:
    SharedPtr() : ptr(nullptr), counter(nullptr) {}
    SharedPtr(T* raw_ptr);
    SharedPtr(const SharedPtr& rhs);
    SharedPtr& operator=(const SharedPtr& rhs);

    SharedPtr(SharedPtr&& rhs);
    SharedPtr& operator=(SharedPtr&& rhs);

    ~SharedPtr();

    T* operator->();
    T& operator*();
private:
    void CheckAndDelete();

    T* ptr;
    CounterBlock* counter;
};

template<typename T>
class WeakPtr
{
    friend class SharedPtr<T>;
public:
    WeakPtr() = delete;
    WeakPtr(const SharedPtr<T>& rhs);
    WeakPtr(const WeakPtr& rhs);
    WeakPtr& operator=(const WeakPtr& rhs);
    WeakPtr(WeakPtr&& rhs);
    WeakPtr& operator=(WeakPtr&& rhs);

    ~WeakPtr();

    SharedPtr<T> Lock();
private:
    void CheckAndDelete();
    T* ptr;
    CounterBlock* counter;
};

template<typename T>
T* SharedPtr<T>::operator->()
{
    return ptr;
}

template<typename T>
T& SharedPtr<T>::operator*()
{
    return *ptr;
}

template<typename T>
SharedPtr<T>::SharedPtr(T* raw_ptr)
{
    ptr = raw_ptr;
    counter = new CounterBlock();
    counter->sharedCounter = 1;
    counter->weakCounter = 0;
}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& rhs)
{
    ptr = rhs.ptr;
    counter = rhs.counter;
    ++counter->sharedCounter;
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& rhs)
{
    --counter->sharedCounter;
    CheckAndDelete();
    ptr = rhs.ptr;
    counter = rhs.counter;
    ++counter->sharedCounter;
    return *this;
}

template<typename T>
SharedPtr<T>::SharedPtr(SharedPtr&& rhs)
{
    ptr = rhs.ptr;
    counter = rhs.counter;
    rhs.ptr = nullptr;
    rhs.counter = nullptr;
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr&& rhs)
{
    --counter->sharedCounter;
    CheckAndDelete();

    ptr = rhs.ptr;
    counter = rhs.counter;
    rhs.ptr = nullptr;
    rhs.counter = nullptr;
    return *this;
}

template<typename T>
SharedPtr<T>::~SharedPtr()
{
    if(ptr == nullptr){
        return;
    }
    --counter->sharedCounter;
    CheckAndDelete();
}

template<typename T>
void SharedPtr<T>::CheckAndDelete()
{
    if(counter->sharedCounter == 0){
        delete ptr;
        if(counter->weakCounter == 0){
            delete counter;
        }
    }
}



template<typename T>
SharedPtr<T> WeakPtr<T>::Lock()
{
    if(counter->sharedCounter != 0){
        SharedPtr shared_ptr(ptr);
        return shared_ptr;
    }
    else{
        return nullptr;
    }
}

template<typename T>
void WeakPtr<T>::CheckAndDelete()
{
    if(counter->weakCounter == 0 && counter->sharedCounter == 0){
        delete counter;
    }
}

template<typename T>
WeakPtr<T>::WeakPtr(const SharedPtr<T>& rhs)
{
    ptr = rhs.ptr;
    counter = rhs.counter;
    ++counter->weakCounter;
}

template<typename T>
WeakPtr<T>::WeakPtr(const WeakPtr& rhs)
{
    ptr = rhs.ptr;
    counter = rhs.counter;
    ++counter->weakCounter;
}

template<typename T>
WeakPtr<T>& WeakPtr<T>::operator=(const WeakPtr& rhs)
{
    --counter->weakCounter;
    CheckAndDelete();
    ptr = rhs.ptr;
    counter = rhs.counter;
    ++counter->weakCounter;
    return *this;
}

template<typename T>
WeakPtr<T>::WeakPtr(WeakPtr&& rhs)
{
    ptr = rhs.ptr;
    counter = rhs.counter;
    rhs.ptr = nullptr;
    rhs.counter = nullptr;
}

template<typename T>
WeakPtr<T>& WeakPtr<T>::operator=(WeakPtr&& rhs)
{
    --counter->weakCounter;
    CheckAndDelete();

    ptr = rhs.ptr;
    counter = rhs.counter;
    rhs.ptr = nullptr;
    rhs.counter = nullptr;
    return *this;
}

template<typename T>
WeakPtr<T>::~WeakPtr()
{
    --counter->weakCounter;
    CheckAndDelete();
}

#endif // SHAREDPTR_H
