#ifndef SIMMANAGER_H
#define SIMMANAGER_H

#include "util.h"
#include "field.h"
#include "entity.h"

class SimManager
{
public:
    SimManager(i16 field_h, i16 field_w);
    SimManager(const SimManager&) = delete;
    SimManager(SimManager&&) = delete;
    SimManager& operator=(const SimManager&) = delete;
    SimManager& operator=(SimManager&&) = delete;

    ~SimManager();

    void Step();
    void AddEntity(u16 x, u16 y, std::string type);

    void RandomSpawn(i16 obstNum, i16 herbNum, i16 predNum);

    template<class TEntity, class ...Args>
    void Spawn(Coords coords, Args&&... args)
    {
        Entity* entity =
                new TEntity(this, field->GetCellByCoords(coords), std::forward<Args>(args)...);
        field->GetCellByCoords(coords)->SetEntity(entity);
        entities.push_back(entity);
    }

private:
    Field* field;
    std::vector<Entity*> entities;

    i16 total_buried;
};

#endif // SIMMANAGER_H
