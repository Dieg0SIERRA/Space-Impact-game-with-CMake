/**
 * @file
 * @brief     Asteroid class
 * @copyright Diego SIERRA
 */

#ifndef ASTEROID_H
#define ASTEROID_H

#include "gameObject.h"

#define ASTEROID_SPEED 26

class Asteroid : public GameObject
{
public:
    Asteroid(int x, int y, uint8_t health, uint8_t speed);
    ~Asteroid() = default;

    virtual void move() override;
    virtual void draw() override ;
    //virtual void draw(int x, int y) override ;
    virtual void erase() override ;

    void setSpeed(uint8_t speed);
    void setSize(uint8_t speed);
    uint8_t getSpeed() const ;
    uint8_t getSize() const ;
    void downSpeed();

private:
    uint8_t m_speed;
    uint8_t m_size;
};

#endif
