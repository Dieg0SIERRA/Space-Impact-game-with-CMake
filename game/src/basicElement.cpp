/**
 * @file
 * @brief     Basic elements class
 * @copyright Diego SIERRA
 */

#include "basicElement.h"


BasicElement::BasicElement()
{
    m_x = 0;
    m_y = 0;
    m_health = 0;
    m_collision = false;
}

int BasicElement::getX() {    return m_x;    }
int BasicElement::getY() {    return m_y;    }
int BasicElement::getHealth() {    return m_health;    }

void BasicElement::setX(int value) {    m_x = value;    }
void BasicElement::setY(int value) {    m_y = value;    }
void BasicElement::setHealth(char value)
{

}

void BasicElement::draw(int x, int y)
{}

void BasicElement::move(int x, int y)
{}

void BasicElement::collisionDetection(int x, int y)
{}

void BasicElement::erase(int x, int y)
{

}