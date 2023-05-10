#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>

#include "RenderConfig.h"
#include "entity.h"

class SimManager;

class Obstacle: public Entity
{
public:
    Obstacle(SimManager*mgr, Cell* _cell);
    void Tick();
    void Render();
};

#endif // OBSTACLE_H
