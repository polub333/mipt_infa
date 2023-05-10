#include "include/behaviourmitosis.h"
#include "include/cell.h"
#include "include/field.h"
#include "include/herbivorous.h"
#include "include/simconfig.h"
#include "include/types.h"
#include "include/coords.h"
#include "include/simmanager.h"

#include <algorithm>
#include <random>
#include <string>

BehaviourApplicationResult BehaviourMitosis::Apply()
{
    if(animal->satiety < min_satiety_to_mitosis){
        return BehaviourApplicationResult::R_CONTINUE;
    }
    Coords coords = animal->GetCell()->GetCoords();
    Coords targetCoords = coords;

    std::string direction = "lrud";
    for(u16 i = 0; i < 4; ++i){
        std::swap(direction[std::rand() % 4], direction[rand() % 4]);
    }

    for(i16 i = 0; i < 4; ++i){
        targetCoords = coords;
        switch(direction[i]){
            case 'l': --targetCoords.x; break;
            case 'r': ++targetCoords.x; break;
            case 'u': --targetCoords.y; break;
            case 'd': ++targetCoords.y; break;
        }
        auto width = animal->GetCell()->GetField()->width;
        auto height = animal->GetCell()->GetField()->height;
        coords.x = (coords.x + width) % width;
        coords.y = (coords.y + height) % height;

        Cell* targetCell = animal->GetCell()->GetField()->GetCellByCoords(targetCoords);
        if(targetCell->GetEntity() == nullptr){
            animal->Clone(targetCell);
            return BehaviourApplicationResult::R_FINISH;
        }
    }
    return BehaviourApplicationResult::R_CONTINUE;
}
