#pragma once
#include "entity.h"
#include "paddle.h"
#include <raylib.h>

class Ball : public Entity
{
private:
    int radius;
    Vec2i acceleration;
    int speed;
    void Bounce(int, int);
    /**
     * @brief the reference to the bounceSound asset
     * @note the "m_" prefix makes an inconsistent name convention, however this is intentional
     * in order to prevent confusion with the asset name defined in main.cpp
    */
    Sound m_bounceSound;
public:
    Ball(Sound bounceSound);
    void Tick();
    void Render();
    void CheckForPaddleCollision(Paddle*);
};