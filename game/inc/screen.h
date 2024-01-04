/**
 * @file
 * @brief     Screen class
 * @copyright Diego SIERRA
 */

#ifndef SCREEN_H
#define SCREEN_H

#include "tools.h"

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
    void levelUp(uint8_t value);
    void resetHealth();
    void limits();
    void printHealth();
    void homeScreen();
    void endScreen();
    void printStatusBar();

private:
    uint8_t m_level;
    int m_score;
    int m_life;
    int m_health;
};

#endif
