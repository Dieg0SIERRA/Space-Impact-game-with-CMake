/**
 * @file
 * @brief     Factory enemies class
 * @copyright Diego SIERRA
 */

#ifndef FACTORY_ENEMIES_H
#define FACTORY_ENEMIES_H

#include "asteroid.h"

using VECT_Asteroid = std::vector<Asteroid>;
//class Asteroid;

class FactoryEnemies 
{
public:

    virtual Asteroid *createAsteroid(std::vector<int> params) = 0;
    //virtual Obstacle *createObstacle() = 0;
    //TODO: implement the other types of enemies

private:
};

#endif
