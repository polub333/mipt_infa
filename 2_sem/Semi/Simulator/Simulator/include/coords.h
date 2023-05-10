#ifndef COORDS_H
#define COORDS_H

#include "types.h"

class Coords
{
public:
    Coords(i16 _x, i16 _y): x(_x), y(_y) {}
    i16 x;
    i16 y;
};

#endif // COORDS_H
