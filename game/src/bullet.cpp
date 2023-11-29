/**
 * @file
 * @brief     Bullet class
 * @copyright Diego SIERRA
 */

#include "bullet.h"

Bullet::Bullet(int x, int y)
{
    setX(x);
    setY(y);
}

void Bullet::move()
{
    bool bulletOut = false;
    int valueY = getY();
    int valueX = getX();
    gotoxy(valueX, valueY);      printf("  ");

    if (valueY > 4) {   setY(--valueY);  }
    else if (valueY == 4)    {  bulletOut = true;  }   
    
    draw(valueX, valueY);
    //return bulletOut;
}

void Bullet::draw(int x, int y){
    gotoxy(x, y);      printf("*");
}

void Bullet::erase(int x, int y) 
{
    gotoxy(x, y);      printf("  ");
}
