/**
 * @file
 * @brief     Spaceship class
 * @copyright Diego SIERRA
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "gameObject.h"

#define X_init 37
#define Y_init 30

class Spaceship : public GameObject
{
public:
    Spaceship();
    ~Spaceship() = default;

    virtual void move() override;
    virtual void draw() override ;
    //virtual void draw(int x, int y) override ;
    virtual void erase(int x, int y) override ;

    void collisionDetection(int x, int y) const ;
    void setLifes(char value);
    int getLifes();
    void createShip();
    void animationShipDie();

private:
    int m_lifes;
    
};
#endif
