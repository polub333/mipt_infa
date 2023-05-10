#ifndef ANIMAL_H
#define ANIMAL_H

#include <vector>

#include "types.h"
#include "entity.h"

class Behaviour;
class SimManager;

class Animal: public Entity
{
    friend class Behaviour;
public:
    //using Entity::Entity;
    Animal(SimManager* mgr, Cell* cell, i16 satiety);
    Animal(SimManager* mgr, Cell* cell);
    virtual void GetBehaviours() = 0;
    virtual void Clone(Cell* cell) = 0;
    virtual void Render() = 0;
    virtual void Tick();
    i16 satiety;
protected:
    std::vector<Behaviour*> behaviours;
};

#endif // ANIMAL_H
