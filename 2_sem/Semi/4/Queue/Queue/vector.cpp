#include "vector.h"

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
        Realloc(2*reserved);
    }
    data[size] = elem;
    ++size;
}
