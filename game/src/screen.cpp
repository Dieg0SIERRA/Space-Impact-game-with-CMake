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

void Screen::init()
{
    //system("cls");
    //system("Color 0A");
}

void Screen::homeScreen()
{
    system("cls");
    system("Color 0A");

    gotoxy(0, 2);   for(auto it : startGame) {  std::cout << it << "\n"; }

    gotoxy(50, 30);   printf(" NEW GAME  (press 'p')");
    gotoxy(50, 33);   printf(" LOAD GAME (press 'l')");
    gotoxy(50, 36);   printf(" EXIT GAME (press 'q')");
}

void Screen::endScreen(){
    gotoxy(0, 2);
    for(auto it : gameOver)
    {
        std::cout << it << "\n";
    }
    gotoxy(15, 47); printf("You are a fucking LOOOOOSER!!!!!");
    gotoxy(1, 48);
}

void Screen::modifHealth(char value) 
{
    if(value == '+')    ++m_health;
    else if(value == '-')    --m_health;
    else if(value == 's')    m_health = MAX_HEALTH;
}

void Screen::modifScore(char value) {    
    m_score += value;
    gotoxy(20, 2);      printf("Score %d", m_score);
    }

void Screen::modifLife(char value)
{
    if(value == '+')    ++m_life;
    else if(value == '-')    --m_life;
    else if(value == 's')    m_life = MAX_LIFE;
}
void Screen::healthToZero()
{
    --m_life;
    m_health = MAX_HEALTH;
    gotoxy(50, 2);      printf("LIFES %d", m_life);
    printHealth();
}

void Screen::printScreen(ScreenElement element)
{
    switch (element)
    {
    case SCORE:
        gotoxy(20, 2);      printf("Score %d", m_score);
        break;
    case LEVEL:
        gotoxy(10, 2);      printf("LEVEL %d", m_level);
        break;
    case LIFE:
        gotoxy(50, 2);      printf("LIFES %d", m_life);
        break;
    case HEALTH:
        printHealth();
        break;
    case ALL:
        gotoxy(10, 2);      printf("LEVEL %d", m_level);
        gotoxy(20, 2);      printf("Score %d", m_score);
        gotoxy(50, 2);      printf("LIFES %d", m_life);
        gotoxy(63, 2);      printf("Health ");
        printHealth();
    default:
        break;
    }
}

void Screen::printEnd()
{
    gotoxy(70, 2);      printf(" ...                        ");
}

void Screen::limits()
{
    for (int i = 2; i < X_LIMIT; i++)
    {
       gotoxy(i, 3);        printf("%c", 205);
       gotoxy(i, Y_LIMIT);  printf("%c", 205); 
    }
    for (int i = 4; i < Y_LIMIT; i++)
    {
       gotoxy(2, i);            printf("%c", 186);
       gotoxy(X_LIMIT-2, i);    printf("%c", 186); 
    }
    gotoxy(2, 3);                  printf("%c", 201);
    gotoxy(2, Y_LIMIT);            printf("%c", 200);
    gotoxy(X_LIMIT-2, 3);          printf("%c", 187);
    gotoxy(X_LIMIT-2, Y_LIMIT);    printf("%c", 188);
    printf("\n");
}

void Screen::printHealth()
{
    int i, j = 0;
    gotoxy(73, 2);      printf("\t");
    for (i = 0; i < m_health; i++)
    {
        gotoxy(73+j+i, 2);      printf("%c ",3);
        j++;
    }
}

void Screen::printStatusBar(){
    gotoxy(20, 2);
    printf("LEVEL  %d \t Score  %d \t LIFES  %d \t Health  ", m_level, m_score, m_life);
    printHealth();
}
