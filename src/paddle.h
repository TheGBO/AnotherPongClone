#pragma once
#include "entity.h"

class Paddle : public Entity
{
private:
    int width;
    int height;
public:
    Paddle();
    void Tick();
    void Render();
    void Move(int);
    int getWidth();
    int getHeight();
};