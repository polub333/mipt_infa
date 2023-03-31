#ifndef ENTITY_H
#define ENTITY_H

class Cell;

class Entity
{
public:
    virtual void Tick() = 0;
    virtual void Render() = 0;
    Cell* GetCell();
    void SetCell(Cell* _cell);
private:
    Cell* cell;
};

#endif // ENTITY_H
