#include "entity.h"
#include <iostream>

/**
 * @brief Constructor method for a new Entity
 * @note This is called when you create an entity,
 * it's also where the initialization logic of the game/app should be.
 * @note `use case:` e.g. assignining values to variables
 */
Entity::Entity()
{
    std::cout << "Entity instance created" << std::endl;
}


void Entity::Tick()
{

}

/**
 * @brief This method is called everytime a draw call from the game loop happens,
 * Code related to drawing graphics for example should be in this function.
 * 
 */
void Entity::Render()
{

}

Entity::~Entity() { }