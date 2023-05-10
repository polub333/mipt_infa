#include "include/cell.h"
#include <include/simconfig.h>
#include <include/behaviourherbivorouseat.h>

BehaviourApplicationResult BehaviourHerbivorousEat::Apply()
{
    if(animal->satiety > max_satiety_to_eat)
        return BehaviourApplicationResult::R_CONTINUE;
    if(animal->GetCell()->GetGrass() < min_grass_amount_to_eat)
        return BehaviourApplicationResult::R_CONTINUE;
    i16 want_to_eat = max_satiety - animal->satiety;
    animal->satiety += animal->GetCell()->ConsumeGrass(want_to_eat);
    return BehaviourApplicationResult::R_FINISH;
}
