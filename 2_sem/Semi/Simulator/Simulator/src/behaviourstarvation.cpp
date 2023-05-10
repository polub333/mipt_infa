#include "include/behaviourstarvation.h"
#include "include/simconfig.h"
#include "include/util.h"

BehaviourApplicationResult BehaviourStarvation::Apply()
{
    animal->satiety -= satiety_per_tick;
    if(animal->satiety < 0){
        animal->Kill();
        return BehaviourApplicationResult::R_FINISH;
    }
    return BehaviourApplicationResult::R_CONTINUE;
}
