#include "paddle.h"
#include <raylib.h>
#include "globals.h"

Paddle::Paddle()
{
    width = 16;
    height = 64;
    position.y = screenHeight/2;
}

void Paddle::Tick()
{

}

void Paddle::Render()
{
    DrawRectangle(position.x, position.y, width, height, WHITE);
}

void Paddle::Move(int yVelocity)
{
    if(!(position.y > screenHeight-height) && !(position.y < 0+height))
    {
        position.y += yVelocity;
    }
}

int Paddle::getWidth()
{
    return this->width;
}

int Paddle::getHeight()
{
    return this->height;
}