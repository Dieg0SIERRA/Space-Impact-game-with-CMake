/**
 * @file
 * @brief     Basic elements class
 * @copyright Diego SIERRA
 */

#ifndef BASIC_ELEMENT_H
#define BASIC_ELEMENT_H

#include "tools.h"

class BasicElement 
{
public:
    BasicElement();
    ~BasicElement() = default;

    virtual void erase(int x, int y) const;

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

