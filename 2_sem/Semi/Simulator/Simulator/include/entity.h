#ifndef ENTITY_H
#define ENTITY_H

class SimManager;
class Cell;

enum struct EntityState {
    S_ALIVE,
    S_DEAD
};

class Entity
{
public:
    Entity(SimManager* mgr, Cell* _cell);
    virtual void Tick() = 0;
    virtual void Render() = 0;
    Cell* GetCell();
    void SetCell(Cell* _cell);

    virtual void Kill();
    EntityState GetState();
    SimManager* manager;
protected:
    Cell* cell;
    EntityState state;
};

#endif // ENTITY_H
