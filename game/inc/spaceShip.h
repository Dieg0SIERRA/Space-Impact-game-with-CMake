/**
 * @file
 * @brief     Spaceship class
 * @copyright Diego SIERRA
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "basicElement.h"

class Spaceship : public BasicElement
{
public:
    Spaceship();
    ~Spaceship() = default;

    void draw() const;
    void move();
    void erase() const;
    void collisionDetection(int x, int y);
    void setLifes(char value);
    int getLifes();
    void animationShipDie();

private:
    int m_lifes;    
};
#endif
