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

    virtual void draw(int x, int y);
    virtual void move(int x, int y) 
    virtual void collisionDetection(int x, int y);
	virtual void erase(int x, int y);

    int getX();
    int getY();
    int getHealth();
    void setX(int value);
    void setY(int value);
    void setHealth(char value);

private:
    int m_x;
    int m_y;
    int m_health;
    bool m_collision;
    
};

#endif

