#ifndef ANIMAL_H
#define ANIMAL_H

#include "types.h"
#include "entity.h"

class Animal: public Entity
{
public:
    virtual Animal* Clone() = 0;
    virtual void Tick() = 0;
    i16 satiety;
};

#endif // ANIMAL_H
