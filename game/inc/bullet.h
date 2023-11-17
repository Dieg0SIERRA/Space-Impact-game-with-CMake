/**
 * @file
 * @brief     Bullet class
 * @copyright Diego SIERRA
 */

#ifndef BULLET_H
#define BULLET_H

#include "basicElement.h"

class Bullet : public BasicElement
{
public:
    Bullet(int x, int y);
    ~Bullet() = default;

    bool move();
    //void erase();

private:
};

#endif
