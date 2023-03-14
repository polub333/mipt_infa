#include "vector.h"
#include <iostream>

Vector::Vector()
{
    size = 0;
    reserved = defaultSize;
    data = new i64[defaultSize];
}

Vector::Vector(u64 n)
{
    data = nullptr;
    size = 0;
    reserved = 0;
    Realloc(n);
    for (u64 i = 0; i < n; ++i){
        data[i] = 0;
    }
    size = n;
}

Vector::~Vector()
{
    delete[] data;
}

Vector::Vector(const Vector& v)
{
    size = v.Size();
    reserved = v.Size();
    data = new i64[reserved];
    for (u64 i = 0; i < v.Size(); ++i){
        data[i] = v.data[i];
    }
}

Vector& Vector::operator=(const Vector& v)
{
    if(this == &v){
        return *this;
    }
    Vector tmp(v);
    std::swap(size, tmp.size);
    std::swap(reserved, tmp.reserved);
    std::swap(data, tmp.data);
    return *this;
}

Vector::Vector(Vector&& v)
{
    size = v.Size();
    data = v.data;
    reserved = v.reserved;
    v.data = nullptr;
    v.size = 0;
    v.reserved = 0;
}

Vector& Vector::operator=(Vector&& v)
{
    if(this == &v){
        return *this;
    }
    Vector tmp(std::move(v));
    std::swap(size, tmp.size);
    std::swap(reserved, tmp.reserved);
    std::swap(data, tmp.data);
    return *this;
}

void Vector::Realloc(u64 n)
{
    if (reserved >= n){
        return;
    }
    i64* newData = new i64[n];
    for (u64 i = 0; i < size; ++i){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    reserved = n;
}

void Vector::Resize(u64 n)
{
    if(n > reserved){
        Realloc(n);
    }
    size = n;
}

i64& Vector::operator[](u64 index)
{
    return data[index];
}

u64 Vector::Size() const {
    return size;
}

void Vector::PopBack()
{
    --size;
}

void Vector::PushBack(i64 elem)
{
    if(reserved <= size){
        if(reserved == 0){
            Realloc(1);
        }
        else{
            Realloc(2*reserved);
        }
    }
    data[size] = elem;
    ++size;
}

void Vector::Clear()
{
    size = 0;
    reserved = 0;
    delete[] data;
    data = nullptr;
}
