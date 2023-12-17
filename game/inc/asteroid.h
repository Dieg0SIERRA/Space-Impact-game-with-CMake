/**
 * @file
 * @brief     Asteroid class
 * @copyright Diego SIERRA
 */

#ifndef ASTEROID_H
#define ASTEROID_H

#include "gameObject.h"

class Asteroid : public GameObject
{
public:
    Asteroid(int x, int y);
    ~Asteroid() = default;

    virtual void move() override;
    virtual void draw() override ;
    //virtual void draw(int x, int y) override ;
    virtual void erase() override ;

    void setSpeed(int speed);
    void setSize(uint8_t speed);
    int getSpeed() const ;
    uint8_t getSize() const ;
    void downSpeed();

    void collisionDetection(int x, int y) const;

private:
    int m_speed;
    uint8_t m_size;
};

#endif
