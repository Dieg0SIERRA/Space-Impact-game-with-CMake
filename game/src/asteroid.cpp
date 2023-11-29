/**
 * @file
 * @brief     Asteroid class
 * @copyright Diego SIERRA
 */

#include "asteroid.h"

Asteroid::Asteroid(int x, int y) : BasicElement()
{
  setX(x);
  setY(y);  
}

void Asteroid::draw(int x, int y)
{
  gotoxy(x, y);      printf(" %c", 184);
}

void Asteroid::move() 
{
    int valueY = getY();
    int valueX = getX();

    if (valueY > 3 && valueY < 33) {
        gotoxy(valueX, valueY);      printf("  ");
    }
    if (valueY >= 32)
    {
        valueX = rand()%LIM_RIGHT + 3;
        valueY = 4;
    }
    else {
        ++valueY;
    }
        
    Sleep(20);
    draw(valueX, valueY);
    setY(valueY);
    setX(valueX);
}

void Asteroid::collisionDetection(int x, int y)
{

}
