#include <include/entity.h>
#include <include/cell.h>

Entity::Entity(SimManager* mgr, Cell* _cell)
{
    manager = mgr;
    cell = _cell;
    state = EntityState::S_ALIVE;
}

Cell* Entity::GetCell()
{
    return cell;
}

void Entity::SetCell(Cell* _cell)
{
    cell = _cell;
}

void Entity::Kill()
{
    state = EntityState::S_DEAD;
    if(cell != nullptr){
        cell->SetEntity(nullptr);
    }
    cell = nullptr;
}

EntityState Entity::GetState()
{
    return state;
}
