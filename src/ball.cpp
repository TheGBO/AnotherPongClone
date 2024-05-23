#include "ball.h"
#include <raylib.h>
#include "globals.h"

Ball::Ball(Sound bounceSound)
{
    speed = 8;
    radius = 8;
    position.x = screenWidth/2;
    position.y = screenHeight/2;
    acceleration.x = speed;
    acceleration.y = speed;
    this->m_bounceSound = bounceSound;
}

void Ball::Tick()
{
    position.x += acceleration.x;
    position.y += acceleration.y;
    if(position.x > screenWidth - radius || position.x < 0 + radius)
    {
        Bounce(-1, 1);
    }
    if(position.y > screenHeight -radius || position.y < 0 + radius)
    {
        Bounce(1, -1);
    }
}

void Ball::Render()
{
    DrawCircle(position.x, position.y, radius, WHITE);
}

void Ball::Bounce(int xBounce, int yBounce)
{
    PlaySound(this->m_bounceSound);
    acceleration.x *= xBounce;
    acceleration.y *= yBounce;
}

void Ball::CheckForPaddleCollision(Paddle* paddleReference)
{
    
}