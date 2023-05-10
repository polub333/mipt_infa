#include "include/animal.h"
#include "include/behaviour.h"
#include "include/simconfig.h"
#include "include/util.h"

void Animal::Tick()
{
    for (auto &b : behaviours){
        if(b->Apply() != BehaviourApplicationResult::R_CONTINUE){
            return;
        }
    }
    ASSERT(false);
}

Animal::Animal(SimManager* mgr, Cell* cell, i16 satiety=-1)
    : Entity(mgr, cell),
      satiety(satiety)
{

}

Animal::Animal(SimManager* mgr, Cell* cell)
    : Entity(mgr, cell),
      satiety(satiety_default)
{

}
