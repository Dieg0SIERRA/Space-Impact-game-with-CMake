/**
 * @file
 * @brief     Spaceship class
 * @copyright Diego SIERRA
 */

#include "spaceShip.h"

Spaceship::Spaceship() : BasicElement()
{
  setX(37);
  setY(30);
  setHealth('s');
  setLifes('s');
}

int Spaceship::getLifes() {    return m_lifes;    }
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

    gotoxy(valueX, valueY);      printf("  %c", 30);
    gotoxy(valueX, valueY+1);    printf(" %c%c%c", 40, 207, 41);
    gotoxy(valueX, valueY+2);    printf("%c%c %c%c", 30, 190, 190, 30);
    gotoxy(0, 34);
}

void Spaceship::move()
{
    int valueY = getY();
    int valueX = getX();
    char touch;

    if (kbhit())    //Fonction to detect if a touch was 
    {
        touch = getch();
        erase();
        if (touch == 'q' && valueX > 3)      valueX--;
        if (touch == 'd' && valueX+6 < 77)   valueX++;
        if (touch == 'z' && valueY > 4)      valueY--;
        if (touch == 's' && valueY+3 < 33)   valueY++;
        
        setX(valueX);
        setY(valueY);                       
        draw();
    }
}

void Spaceship::collisionDetection(int x, int y) 
{}

void Spaceship::erase() 
{
    int valueY = getY();
    int valueX = getX();

    gotoxy(valueX, valueY);      printf("         ", 30);
    gotoxy(valueX, valueY+1);    printf("         ", 30);
    gotoxy(valueX, valueY+2);    printf("         ", 30);
}

void Spaceship::animationShipDie()
{
    int valueY = getY();
    int valueX = getX();

    erase();
    system("Color 0C");
    gotoxy(valueX, valueY);        printf("   **   ");
    gotoxy(valueX, valueY+1);      printf("  ****  ");
    gotoxy(valueX, valueY+2);      printf("   **   ");
    Sleep(500);
    erase();
    gotoxy(valueX, valueY);        printf(" *  **  *");
    gotoxy(valueX, valueY+1);      printf("   ****  ");
    gotoxy(valueX, valueY+2);      printf(" *  **  *");
    Sleep(500);
    erase();
    system("Color 0A");
    draw();
}
