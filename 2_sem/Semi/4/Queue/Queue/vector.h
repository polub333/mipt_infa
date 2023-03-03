#ifndef VECTOR_H
#define VECTOR_H

#include <cstdint>

using u64 = uint64_t;
using i64 = int64_t;

class Vector
{
public:
    Vector();
    Vector(u64 size);
    ~Vector();
    void PushBack(i64 elem);
    void PopBack();
    i64& operator[](u64 index);
    u64 Size() const;
    void Resize(u64 n);
    void Realloc(u64 n);
private:
    i64* data;
    u64 size, reserved;
    const u64 defaultSize = 2;
};

#endif // VECTOR_H
