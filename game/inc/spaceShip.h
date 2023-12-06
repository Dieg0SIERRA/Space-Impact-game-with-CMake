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
    virtual void erase(int x, int y) override ;
    
    void setKeyDirection(int value);
    void setLifes(char value);
    int getKeyDirection();
    int getLifes();
    void createShip();
    void animationShipDie();
    void collisionDetection(int x, int y) const ;

private:
    int m_lifes;
    int m_keyDirection;
    
};
#endif
