#include <include/obstacle.h>

Obstacle::Obstacle(SimManager* mgr, Cell* _cell)
    : Entity(mgr, cell)
{

}

void Obstacle::Tick()
{

}

void Obstacle::Render()
{
    std::cout << render_strings::obstacle;
}
