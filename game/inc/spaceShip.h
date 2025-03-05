/**
 * @file
 * @brief     Spaceship class
 * @copyright Diego SIERRA
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "gameObject.h"

#define X_init  37
#define Y_init  30
#define RIGHT   100
#define LEFT    113
#define UP      122
#define DOWN    115

class Spaceship : public GameObject
{
public:
    Spaceship();
    ~Spaceship() = default;

    virtual void move() override;
    virtual void draw() override ;
    //virtual void draw(int x, int y) override ;
    virtual void erase() override ;
    
    void setKeyDirection(int value);
    void setLifes(char value);
    int getKeyDirection();
    int getLifes();
    void animationShipDie();

private:
    int m_lifes{0};
    int m_keyDirection{0};
    
};
#endif
