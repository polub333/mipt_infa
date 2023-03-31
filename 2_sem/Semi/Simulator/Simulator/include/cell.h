#ifndef CELL_H
#define CELL_H

#include "types.h"
#include "entity.h"

class Field;

class Cell
{
public:
    void Tick();
    void Render();
    i16 GetGrass();
    void SetGrass(const i16& grass);
    Entity* GetEntity();
    void SetEntity(const Entity& entity);
private:
    Entity* entity;
    int16_t n_grass;
    Field* filed;
};

#endif // CELL_H
