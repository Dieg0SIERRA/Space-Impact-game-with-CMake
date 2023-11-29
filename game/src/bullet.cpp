/**
 * @file
 * @brief     Bullet class
 * @copyright Diego SIERRA
 */

#include "bullet.h"

Bullet::Bullet(int x, int y) : BasicElement()
{
  setX(x);
  setY(y);
}

bool Bullet::move()
{
    bool bulletOut = false;
    int valueY = getY();
    int valueX = getX();
    gotoxy(valueX, valueY);      printf("  ");

    if (valueY > 4) {   setY(--valueY);  }
    else if (valueY == 4)    {  bulletOut = true;  }   
    
    gotoxy(valueX, valueY);      printf("*");
    return bulletOut;
}
