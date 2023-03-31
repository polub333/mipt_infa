#ifndef FIELD_H
#define FIELD_H

#include "types.h"
#include "cell.h"

class Field
{
private:
    i16 n;
    i16 m;
public:
    Field() = delete;
    Field(const Field&) = delete;
    Field& operator=(const Field&) = delete;
    Field(Field&&) = delete;
    Field&& operator=(Field&&) = delete;

    Field(i16 n, i16 m);
    ~Field();

    void Tick();
    void Render();
    Cell** cells;
};

#endif // FIELD_H
