/**
 * @file
 * @brief     Screen class
 * @copyright Diego SIERRA
 */

#ifndef SCREEN_H
#define SCREEN_H

#include "tools.h"


class Screen 
{
public:
    Screen();

    int getLevel() const;
    int getScore() const;
    int getLife() const;
    int getHealth() const;

    void modifHealth(char value);
    void modifScore(char value);
    void modifLife(char value);
    void printScreen(ScreenElement element);
    void limits();
    void printHealth();

private:
    int m_level;
    int m_score;
    int m_life;
    int m_health;
    
    
};

#endif
