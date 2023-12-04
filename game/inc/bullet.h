/**
 * @file
 * @brief     Bullet class
 * @copyright Diego SIERRA
 */

#ifndef BULLET_H
#define BULLET_H

#include "gameObject.h"

class Bullet : public GameObject
{
public:
    Bullet(int x, int y);
    ~Bullet() = default;

    virtual void move() override;
    virtual void draw() override ;
    //virtual void draw(int x, int y) override ;
    virtual void erase(int x, int y) override ;

private:
};

#endif
