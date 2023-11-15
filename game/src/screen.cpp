/**
 * @file
 * @brief     Screen class
 * @copyright Diego SIERRA
 */

#include "screen.h"

Screen::Screen()
{
    m_level = 1;
    m_score = 0;
    m_life = MAX_LIFE;
    m_health = MAX_HEALTH;
}

int Screen::getLevel() const {    return m_level;    }

int Screen::getScore() const {    return m_score;    }

int Screen::getLife() const {    return m_life;    }

int Screen::getHealth() const {    return m_health;    }

void Screen::modifHealth(char value) 
{
}

void Screen::modifScore(char value) {    
    }

void Screen::modifLife(char value)
{
}


void Screen::printScreen(ScreenElement element)
{

}


void Screen::limits()
{

}


void Screen::printHealth()
{

}