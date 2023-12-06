/**
 * @file
 * @brief     Spaceship class
 * @copyright Diego SIERRA
 */

#include "spaceShip.h"

Spaceship::Spaceship()
    :   m_lifes(0), m_keyDirection(0)
{
}

void Spaceship::createShip(){

    setX(37);
    setY(30);
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

//void Spaceship::draw(int x, int y)
//{
//    Tools::gotoxy(x, y);      printf("  %c", 30);
//    Tools::gotoxy(x, y+1);    printf(" %c%c%c", 40, 207, 41);
//    Tools::gotoxy(x, y+2);    printf("%c%c %c%c", 30, 190, 190, 30);
//    Tools::gotoxy(0, 34);
//}

void Spaceship::draw()
{
    int valueY = getY();
    int valueX = getX();

    Tools::gotoxy(valueX, valueY);      printf("  %c", 30);
    Tools::gotoxy(valueX, valueY+1);    printf(" %c%c%c", 40, 207, 41);
    Tools::gotoxy(valueX, valueY+2);    printf("%c%c %c%c", 30, 190, 190, 30);
    Tools::gotoxy(0, 34);
}

void Spaceship::move()
{
    //int valueY = getY();
    //int valueX = getX();
    //char touch;

    if (getKeyDirection() != 0){
        int valueY = getY();
        int valueX = getX();

        erase(valueX, valueY);
        if (getKeyDirection() == LEFT && valueX > 3)      valueX--;
        if (getKeyDirection() == RIGHT && valueX+6 < 77)   valueX++;
        if (getKeyDirection() == UP && valueY > 4)      valueY--;
        if (getKeyDirection() == DOWN && valueY+3 < 33)   valueY++;
    
        setX(valueX);
        setY(valueY);
    }
    
/*
    if (_kbhit())    //Fonction to detect if a touch was 
    {
        touch = _getch();
        erase(valueX, valueY);
        if (touch == 'q' && valueX > 3)      valueX--;
        if (touch == 'd' && valueX+6 < 77)   valueX++;
        if (touch == 'z' && valueY > 4)      valueY--;
        if (touch == 's' && valueY+3 < 33)   valueY++;
        
        setX(valueX);
        setY(valueY);                       
        //draw(valueX, valueY);
    }
*/
}

void Spaceship::collisionDetection(int x, int y) const
{}

void Spaceship::erase(int x, int y) 
{
    //int valueY = getY();
    //int valueX = getX();

    Tools::gotoxy(x, y);      printf("         ", 30);
    Tools::gotoxy(x, y+1);    printf("         ", 30);
    Tools::gotoxy(x, y+2);    printf("         ", 30);
}

void Spaceship::animationShipDie()
{
    int valueY = getY();
    int valueX = getX();

    erase(valueX, valueY);
    system("Color 0C");
    Tools::gotoxy(valueX, valueY);        printf("   **   ");
    Tools::gotoxy(valueX, valueY+1);      printf("  ****  ");
    Tools::gotoxy(valueX, valueY+2);      printf("   **   ");
    Sleep(500);
    erase(valueX, valueY);
    Tools::gotoxy(valueX, valueY);        printf(" *  **  *");
    Tools::gotoxy(valueX, valueY+1);      printf("   ****  ");
    Tools::gotoxy(valueX, valueY+2);      printf(" *  **  *");
    Sleep(500);
    erase(valueX, valueY);
    system("Color 0A");
    //draw(valueX, valueY);
    draw();
}
