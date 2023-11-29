/**
 * @file
 * @brief     Spaceship class
 * @copyright Diego SIERRA
 */

#include "spaceShip.h"

Spaceship::Spaceship()
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

void Spaceship::draw(int x, int y)
{
    //int valueY = getY();
    //int valueX = getX();

    gotoxy(x, y);      printf("  %c", 30);
    gotoxy(x, y+1);    printf(" %c%c%c", 40, 207, 41);
    gotoxy(x, y+2);    printf("%c%c %c%c", 30, 190, 190, 30);
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
        erase(valueX, valueY);
        if (touch == 'q' && valueX > 3)      valueX--;
        if (touch == 'd' && valueX+6 < 77)   valueX++;
        if (touch == 'z' && valueY > 4)      valueY--;
        if (touch == 's' && valueY+3 < 33)   valueY++;
        
        setX(valueX);
        setY(valueY);                       
        draw(valueX, valueY);
    }
}

void Spaceship::collisionDetection(int x, int y) const
{}

void Spaceship::erase(int x, int y) 
{
    //int valueY = getY();
    //int valueX = getX();

    gotoxy(x, y);      printf("         ", 30);
    gotoxy(x, y+1);    printf("         ", 30);
    gotoxy(x, y+2);    printf("         ", 30);
}

void Spaceship::animationShipDie()
{
    int valueY = getY();
    int valueX = getX();

    erase(valueX, valueY);
    system("Color 0C");
    gotoxy(valueX, valueY);        printf("   **   ");
    gotoxy(valueX, valueY+1);      printf("  ****  ");
    gotoxy(valueX, valueY+2);      printf("   **   ");
    Sleep(500);
    erase(valueX, valueY);
    gotoxy(valueX, valueY);        printf(" *  **  *");
    gotoxy(valueX, valueY+1);      printf("   ****  ");
    gotoxy(valueX, valueY+2);      printf(" *  **  *");
    Sleep(500);
    erase(valueX, valueY);
    system("Color 0A");
    draw(valueX, valueY);
}
