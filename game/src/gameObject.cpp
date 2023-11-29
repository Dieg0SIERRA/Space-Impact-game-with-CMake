/**
 * @file
 * @brief     Basic elements class
 * @copyright Diego SIERRA
 */

#include "gameObject.h"


//GameObject::GameObject() 
//    : m_x{0}, m_y{0}, m_health{0}
//{
//}

int GameObject::getX() const {    return m_x;    }
int GameObject::getY() const {    return m_y;    }
int GameObject::getHealth() const {    return m_health;    }

void GameObject::setX(int value) {    m_x = value;    }
void GameObject::setY(int value) {    m_y = value;    }
void GameObject::setHealth(char value)
{
    if(value == '+')    ++m_health;
    else if(value == '-')    --m_health;
    else if(value == 's')    m_health = MAX_HEALTH;
}
