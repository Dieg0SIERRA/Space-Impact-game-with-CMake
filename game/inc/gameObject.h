/**
 * @file
 * @brief     Game object class
 * @copyright Diego SIERRA
 */

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "tools.h"

class GameObject 
{
public:
    //GameObject();
    //~GameObject() = default;

    virtual void move() = 0;
    virtual void draw(int x, int y) = 0;
    virtual void erase(int x, int y) = 0;

    int getX() const;
    int getY() const;
    int getHealth() const;
    void setX(int value);
    void setY(int value);
    void setHealth(char value);

private:
    int m_x;
    int m_y;
    int m_health;    
};

#endif
