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
    virtual void draw(int x, int y) override ;
    virtual void erase(int x, int y) override ;
    void collisionDetection(int x, int y) const;

private:
};

#endif
