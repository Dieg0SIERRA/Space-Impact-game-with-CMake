/**
 * @file
 * @brief     Spaceship class
 * @copyright Diego SIERRA
 */

#include "spaceShip.h"

Spaceship::Spaceship()
    :   m_lifes(0), m_keyDirection(0)
{
    setX(X_LIMIT/2);
    setY(Y_LIMIT-2);
    setHealth('s');
    setLifes('s');
}

int Spaceship::getLifes() {    return m_lifes;    }
int Spaceship::getKeyDirection() {   return m_keyDirection;   }
void Spaceship::setKeyDirection(int value){ m_keyDirection = value; }
void Spaceship::setLifes(char value)
{   
    if(value == '+')    ++m_lifes;
    else if(value == '-')    --m_lifes;
    else if(value == 's')    m_lifes = MAX_LIFE; 
}

void Spaceship::draw()
{
    int valueY = getY();
    int valueX = getX();

    Tools::gotoxy(valueX, valueY);        printf("%c", 30);
    Tools::gotoxy(valueX-1, valueY+1);    printf("%c%c%c", 40, 207, 41);
    Tools::gotoxy(valueX-2, valueY+2);    printf("%c%c %c%c", 30, 190, 190, 30);
    Tools::gotoxy(0, 34);
}

void Spaceship::move()
{
    if (getKeyDirection() != 0){
        int valueY = getY();
        int valueX = getX();

        erase();
        if (getKeyDirection() == LEFT && valueX > 3)      valueX--;
        if (getKeyDirection() == RIGHT && valueX+6 < X_LIMIT)   valueX++;
        if (getKeyDirection() == UP && valueY > 4)      valueY--;
        if (getKeyDirection() == DOWN && valueY+3 < Y_LIMIT)   valueY++;
    
        setX(valueX);
        setY(valueY);
    }
}

void Spaceship::erase() 
{
    int valueY = getY();
    int valueX = getX();

    Tools::gotoxy(valueX, valueY);        printf("      ", 30);
    Tools::gotoxy(valueX-1, valueY+1);    printf("      ", 30);
    Tools::gotoxy(valueX-2, valueY+2);    printf("      ", 30);
}

void Spaceship::animationShipDie()
{
    int valueY = getY();
    int valueX = getX();

    erase();
    system("Color 0C");
    Tools::gotoxy(valueX-2, valueY);        printf("  **  ");
    Tools::gotoxy(valueX-2, valueY+1);      printf(" **** ");
    Tools::gotoxy(valueX-2, valueY+2);      printf("  **  ");
    Sleep(500);
    erase();
    Tools::gotoxy(valueX-2, valueY);        printf("*  **  *");
    Tools::gotoxy(valueX-2, valueY+1);      printf("  ****  ");
    Tools::gotoxy(valueX-2, valueY+2);      printf("*  **  *");
    Sleep(500);
    erase();
    system("Color 0A");
    Tools::gotoxy(valueX-2, valueY);        printf("        ");
    Tools::gotoxy(valueX-2, valueY+1);      printf("        ");
    Tools::gotoxy(valueX-2, valueY+2);      printf("        ");
    draw();
}
