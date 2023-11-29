/**
 * @file
 * @brief     Screen class
 * @copyright Diego SIERRA
 */

#ifndef SCREEN_H
#define SCREEN_H

#include "tools.h"

#define X_LIMIT 102
#define Y_LIMIT 45

enum ScreenElement
{
    SCORE,
    LEVEL,
    LIFE,
    HEALTH,
    ALL
};

class Screen 
{
public:
    Screen();
    ~Screen() = default;

    int getLevel() const;
    int getScore() const;
    int getLife() const;
    int getHealth() const;

    void modifHealth(char value);
    void modifScore(char value);
    void modifLife(char value);
    void modifLevel(char value);
    void healthToZero();
    void printScreen(ScreenElement element);
    void limits();
    void printEnd();
    void endScreen();
    void printHealth();

private:
    int m_level;
    int m_score;
    int m_life;
    int m_health;
};

#endif
