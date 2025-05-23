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
    virtual void draw() = 0;
    virtual void erase() = 0;

    int getX() const;
    int getY() const;
    int getHealth() const;
    void setX(int value);
    void setY(int value);
    void setHealth(uint8_t value);
    void modifHealth(char value);

private:
    int m_x{};
    int m_y{};
    uint8_t m_health{0};
};

#endif
