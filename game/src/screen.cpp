/**
 * @file
 * @brief     Screen class
 * @copyright Diego SIERRA
 */

#include "screen.h"
#include "animations.h"

Screen::Screen()
    : m_level(1), m_score(0), m_life(MAX_LIFE), m_health(MAX_HEALTH)
{
}

int Screen::getLevel() const {    return m_level;    }

int Screen::getScore() const {    return m_score;    }

int Screen::getLife() const {    return m_life;    }

int Screen::getHealth() const {    return m_health;    }

void Screen::homeScreen()
{
    system("cls");
    system("Color 0A");

    Tools::gotoxy(0, 2);   for(auto it : startGame) {  std::cout << it << "\n"; }

    Tools::gotoxy(50, 30);   printf(" NEW GAME  (press 'p')");
    Tools::gotoxy(50, 33);   printf(" LOAD GAME (press 'l')");
    Tools::gotoxy(50, 36);   printf(" EXIT GAME (press 'Esc')");
}

void Screen::endScreen(){
    Tools::gotoxy(0, 2);
    for(auto it : gameOver)
    {
        std::cout << it << "\n";
    }
    Tools::gotoxy(15, Y_LIMIT+2); printf("You are a LOOOOOSER!!!!!");
    Tools::gotoxy(1, 48);
}

void Screen::modifHealth(char value) 
{
    if(value == '+')         ++m_health;
    else if(value == '-')    --m_health;
    else if(value == 's')    m_health = MAX_HEALTH;
}

void Screen::modifScore(char value)
{    
    m_score += value;
    Tools::gotoxy(20, 2);
}

void Screen::modifLife(char value)
{
    if(value == '+')         ++m_life;
    else if(value == '-')    --m_life;
    else if(value == 's')    m_life = MAX_LIFE;
}
void Screen::resetHealth()
{
    --m_life;
    m_health = MAX_HEALTH;
    Tools::gotoxy(50, 2);
}

void Screen::limits()
{
    for (int i = 2; i < X_LIMIT; i++)
    {
       Tools::gotoxy(i, 3);        printf("%c", 205);
       Tools::gotoxy(i, Y_LIMIT);  printf("%c", 205); 
    }
    for (int i = 4; i < Y_LIMIT; i++)
    {
       Tools::gotoxy(2, i);            printf("%c", 186);
       Tools::gotoxy(X_LIMIT-1, i);    printf("%c", 186); 
    }
    Tools::gotoxy(2, 3);                  printf("%c", 201);
    Tools::gotoxy(2, Y_LIMIT);            printf("%c", 200);
    Tools::gotoxy(X_LIMIT-1, 3);          printf("%c", 187);
    Tools::gotoxy(X_LIMIT-1, Y_LIMIT);    printf("%c", 188);
    printf("\n");
}

void Screen::printHealth()
{
    int i, j = 0;
    Tools::gotoxy(73, 2);      printf("                   ");
    Tools::gotoxy(73, 2);

    for (i = 0; i < m_health; i++) {    printf("%c ",3);    }
}

void Screen::printStatusBar(){
    Tools::gotoxy(20, 2);
    printf("LEVEL  %d \t Score  %d \t LIFES  %d \t Health  ", m_level, m_score, m_life);
    printHealth();
}
