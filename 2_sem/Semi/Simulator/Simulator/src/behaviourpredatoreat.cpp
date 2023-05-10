#include <include/cell.h>
#include <include/field.h>
#include <include/behaviourpredatoreat.h>
#include "include/herbivorous.h"
#include "include/simconfig.h"
#include "include/types.h"
#include "include/coords.h"

#include <algorithm>

BehaviourApplicationResult BehaviourPredatorEat::Apply()
{
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
        targetCoords.x = (targetCoords.x + width) % width;
        targetCoords.y = (targetCoords.y + height) % height;

        Cell* targetCell = animal->GetCell()->GetField()->GetCellByCoords(targetCoords);
        Animal* targetAnimal = static_cast<Animal*>(targetCell->GetEntity());
        if(dynamic_cast<Herbivorous*>(targetCell->GetEntity()) != nullptr){
            animal->satiety += targetAnimal->satiety;
            if(animal->satiety > max_satiety){
                animal->satiety = max_satiety;
            }
            targetAnimal->Kill();

            animal->GetCell()->SetEntity(nullptr);
            targetCell->SetEntity(animal);
            animal->SetCell(targetCell);

            return BehaviourApplicationResult::R_FINISH;
        }
    }
    return BehaviourApplicationResult::R_CONTINUE;
}
