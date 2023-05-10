#include <include/cell.h>

Cell::Cell(Field* _field, Coords coordinates)
    : field(_field),
      coords(coordinates),
      entity(nullptr),
      n_grass(0),
      grass_grows_rate(5)
{

}

void Cell::Tick()
{
    if(entity == nullptr){
        n_grass += grass_grows_rate;
        if(n_grass > max_grass_amount){
            n_grass = max_grass_amount;
        }
    }
}

void Cell::Render()
{
    if(entity == nullptr){
        std::cout << render_strings::empty_space;
    }
    else{
        entity->Render();
    }
}

i16 Cell::GetGrass()
{
    return n_grass;
}

void Cell::SetGrass(const i16& grass)
{
    n_grass = grass;
}

Entity* Cell::GetEntity()
{
    return entity;
}

void Cell::SetEntity(Entity* _entity)
{
    entity = _entity;
}

i16 Cell::ConsumeGrass(i16 max)
{
    i16 consumed = max;
    if(max > n_grass){
        consumed = n_grass;
    }
    n_grass -= consumed;
    return consumed;
}

void Cell::SetCoords(const Coords& _coords)
{
    coords = _coords;
}

Coords Cell::GetCoords()
{
    return coords;
}

Field* Cell::GetField()
{
    return field;
}
