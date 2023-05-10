#ifndef CELL_H
#define CELL_H

#include <iostream>

#include "types.h"
#include "coords.h"
#include "entity.h"
#include "renderconfig.h"
#include "simconfig.h"

class Field;

class Cell
{
public:
    Cell(Field* _field, Coords coordinates);

    void Tick();
    void Render();
    i16 GetGrass();
    void SetGrass(const i16& grass);
    Entity* GetEntity();
    void SetEntity(Entity* entity);

    void SetCoords(const Coords& coords);
    Coords GetCoords();
    Field* GetField();

    i16 ConsumeGrass(i16 max);
private:
    Field* field;
    Coords coords;
    Entity* entity;
    int16_t n_grass;

    const u16 grass_grows_rate;
};

#endif // CELL_H
