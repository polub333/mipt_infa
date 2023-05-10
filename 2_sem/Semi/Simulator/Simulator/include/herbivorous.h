#ifndef HERBIVOROUS_H
#define HERBIVOROUS_H

#include "animal.h"
#include "behaviour.h"

class SimManager;

class Herbivorous: public Animal
{
public:
    Herbivorous(SimManager* mgr, Cell* _cell);
    Herbivorous(SimManager* mgr, Cell* cell, i16 satiety);
    void GetBehaviours() override;
    void Clone(Cell* cell) override;
    void Render() override;
};

#endif // HERBIVOROUS_H
