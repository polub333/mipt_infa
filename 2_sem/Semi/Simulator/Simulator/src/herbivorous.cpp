#include "include/herbivorous.h"
#include "include/behaviourstarvation.h"
#include "include/behaviourmitosis.h"
#include "include/behaviourherbivorouseat.h"
#include "include/behaviourrandomwalk.h"
#include "include/behaviouridle.h"
#include "include/renderconfig.h"
#include "include/simmanager.h"

#include <iostream>

Herbivorous::Herbivorous(SimManager* mgr, Cell* cell)
    : Animal(mgr, cell)
{
    GetBehaviours();
}

Herbivorous::Herbivorous(SimManager* mgr, Cell* cell, i16 satiety)
    : Animal(mgr, cell, satiety)
{
    GetBehaviours();
}

void Herbivorous::GetBehaviours()
{
    behaviours = {
        new BehaviourStarvation(this),
        new BehaviourMitosis(this),
        new BehaviourHerbivorousEat(this),
        new BehaviourRandomWalk(this),
        new BehaviourIdle(this)
    };
}

void Herbivorous::Render()
{
    std::cout << render_strings::herbivorous;
}

void Herbivorous::Clone(Cell* cell)
{
    manager->Spawn<Herbivorous>(cell->GetCoords(), satiety / 2);
    satiety /= 2;
}
