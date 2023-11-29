/**
 * @file
 * @brief     Basic elements class
 * @copyright Diego SIERRA
 */

#include "basicElement.h"


BasicElement::BasicElement()
    : m_x{0}, m_y{0}, m_health{0}
{
}

int BasicElement::getX() const {    return m_x;    }
int BasicElement::getY() const {    return m_y;    }
int BasicElement::getHealth() const {    return m_health;    }

void BasicElement::setX(int value) {    m_x = value;    }
void BasicElement::setY(int value) {    m_y = value;    }
void BasicElement::setHealth(char value)
{
    if(value == '+')    ++m_health;
    else if(value == '-')    --m_health;
    else if(value == 's')    m_health = MAX_HEALTH;
}

void BasicElement::erase(int x, int y) const
{
    gotoxy(x, y);      printf("  ");
}
