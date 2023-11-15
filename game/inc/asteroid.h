/**
 * @file
 * @brief     Asteroid class
 * @copyright Diego SIERRA
 */

#ifndef ASTEROID_H
#define ASTEROID_H

#include "basicElement.h"

class Asteroid : public BasicElement
{
public:
    Asteroid(int x, int y);

    void draw(int x, int y);
    void move();
    void erase();
    void collisionDetection(int x, int y);

private:
};

#endif
