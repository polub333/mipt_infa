#ifndef FIELD_H
#define FIELD_H

#include <vector>

#include "types.h"
#include "cell.h"

class Field
{
private:


public:
    Field() = delete;
    Field(const Field&) = delete;
    Field& operator=(const Field&) = delete;
    Field(Field&&) = delete;
    Field&& operator=(Field&&) = delete;

    Field(i16 _n, i16 _m);
    ~Field();

    void Tick();
    void Render();
    std::vector<std::vector<Cell*>> cells;

    Cell* GetCellByCoords(Coords coords);

    i16 height;
    i16 width;
};

#endif // FIELD_H
