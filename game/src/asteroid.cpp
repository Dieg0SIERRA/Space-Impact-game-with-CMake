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

}

void Asteroid::erase() 
{

}

void Asteroid::collisionDetection(int x, int y)
{

}
