#pragma once
#include "vec2i.h"

/**
 * @brief The most abstract class for any game object
 * 
 */
class Entity
{
public:
    Vec2i position;
    Entity();
    virtual void Render();
    virtual void Tick();
    virtual ~Entity();
};
