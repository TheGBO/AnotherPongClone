#include <raylib.h>
#include "globals.h"
#include "entity.h"
#include "ball.h"
#include "paddle.h"
#include <list>
#include <iostream>

std::list<Entity*> entities;
//Ball is a "global" variable because it's the most important entity of the game
Ball* ball;

Sound bounceSound;

void LoadAssets()
{
    bounceSound = LoadSound("assets/bounce.wav");
}

void InitGame()
{
    //instantiate ball
    ball = new Ball(bounceSound);
    entities.push_back(ball);

    //instantiate player paddle
    Paddle* playerPaddle = new Paddle();
    playerPaddle->position.x = 16;
    entities.push_back(playerPaddle);

    //instantiate cpu/AI paddle
    Paddle* cpuPaddle = new Paddle();
    cpuPaddle->position.x = screenWidth - 16 - cpuPaddle->getWidth();
    entities.push_back(cpuPaddle);
}


int main()
{
    Color backgroundColour = Color{16,24,32, 255};

    //raylib requires this to play sounda
    InitAudioDevice();
    LoadAssets();
    InitWindow(screenWidth, screenHeight, "Another Pong Clone");
    SetTargetFPS(60);

    InitGame();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(backgroundColour);
        for (Entity* e : entities)
        {
            e->Tick();
            e->Render();

            //check if object is a Paddle
            Paddle* entityToPaddle = dynamic_cast<Paddle*>(e);
            if(entityToPaddle != nullptr)
            {
                ball->CheckForPaddleCollision(entityToPaddle);
            }
        }
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}