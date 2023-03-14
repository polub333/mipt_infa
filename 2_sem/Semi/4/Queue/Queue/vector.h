#ifndef VECTOR_H
#define VECTOR_H

#include <cstdint>
#include <utility>

using u64 = uint64_t;
using i64 = int64_t;

class Vector
{
public:
    Vector();
    Vector(u64 size);
    ~Vector();
    Vector(const Vector& v);
    Vector& operator=(const Vector& v);
    Vector(Vector&& v);
    Vector& operator=(Vector&& v);

    void PushBack(i64 elem);
    void PopBack();
    i64& operator[](u64 index);
    u64 Size() const;
    void Resize(u64 n);
    void Realloc(u64 n);

    void Clear();
private:
    i64* data;
    u64 size, reserved;
    const u64 defaultSize = 2;
};

#endif // VECTOR_H
