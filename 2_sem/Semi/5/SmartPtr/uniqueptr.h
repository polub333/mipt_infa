#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

#include <algorithm>

template<typename T>
class UniquePtr
{
public:
    UniquePtr() : ptr(nullptr) {}
    UniquePtr(T* raw_ptr) : ptr(raw_ptr) {}
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&&);
    UniquePtr& operator=(UniquePtr&&);

    ~UniquePtr() {delete ptr;}

    T* operator->();
    T& operator*();
private:
    T* ptr;
};

template<typename T>
T* UniquePtr<T>::operator->()
{
    return ptr;
}

template<typename T>
T& UniquePtr<T>::operator*()
{
    return *ptr;
}

template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& rhs)
{
    UniquePtr<T> tmp;
    std::swap(tmp.ptr, rhs.ptr);
    std::swap(tmp.ptr, ptr);
}

template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& rhs)
{
    UniquePtr<T> tmp;
    std::swap(tmp.ptr, rhs.ptr);
    std::swap(tmp.ptr, ptr);
    return *this;
}

#endif // UNIQUEPTR_H
