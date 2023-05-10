#include "include/predator.h"
#include "include/behaviourstarvation.h"
#include "include/behaviourmitosis.h"
#include "include/behaviourpredatoreat.h"
#include "include/behaviourrandomwalk.h"
#include "include/behaviouridle.h"
#include "include/renderconfig.h"
#include "include/simmanager.h"

#include <iostream>

Predator::Predator(SimManager* mgr, Cell* cell)
    : Animal(mgr, cell)
{
    GetBehaviours();
}

Predator::Predator(SimManager* mgr, Cell* cell, i16 satiety)
    : Animal(mgr, cell, satiety)
{
    GetBehaviours();
}

void Predator::GetBehaviours()
{
    behaviours = {
        new BehaviourStarvation(this),
        new BehaviourMitosis(this),
        new BehaviourPredatorEat(this),
        new BehaviourRandomWalk(this),
        new BehaviourIdle(this)
    };
}

void Predator::Render()
{
    std::cout << render_strings::predator;
}

void Predator::Clone(Cell* cell)
{
    manager->Spawn<Predator>(cell->GetCoords(), satiety / 2);
    satiety /= 2;
}
