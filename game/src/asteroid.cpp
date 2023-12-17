/**
 * @file
 * @brief     Asteroid class
 * @copyright Diego SIERRA
 */

#include "asteroid.h"

Asteroid::Asteroid(int x, int y)
    : m_speed(15), m_size(1)
{
    setX(x);
    setY(y);
}

void Asteroid::setSpeed(int speed) { m_speed = speed; }
void Asteroid::setSize(uint8_t size) { m_speed = size; }

int Asteroid::getSpeed() const { return m_speed; }
uint8_t Asteroid::getSize() const { return m_size; }
void Asteroid::downSpeed() { --m_speed; }

void Asteroid::draw() 
{
    int valueY = getY();
    int valueX = getX();

    if(valueY >= 3) {
        Tools::gotoxy(valueX, valueY);
        printf("%c", 184);
    }    
}

void Asteroid::move() 
{
    if(getSpeed() == 0) {
        int valueY = getY();
        int valueX = getX();

        if(valueY >= 3){
            if (valueY > 3 && valueY < 33) {
            Tools::gotoxy(valueX, valueY);      printf(" ");
            }
            if (valueY >= 32)
            {
                valueX = rand()%X_LIMIT + 3;
                valueY = 4;
            }
            else {  ++valueY;   }

            setY(valueY);
            setX(valueX);
            setSpeed(15);
        }
    }
/*
    int valueY = getY();
    int valueX = getX();

    if (valueY > 3 && valueY < 33) {
        Tools::gotoxy(valueX, valueY);      printf("  ");
    }
    if (valueY >= 32)
    {
        valueX = rand()%X_LIMIT + 3;
        valueY = 4;
    }
    else {
        ++valueY;
    }
        
    //Sleep(20);
    //draw(valueX, valueY);
    setY(valueY);
    setX(valueX);
*/
}

void Asteroid::erase() 
{
    int valueY = getY();
    int valueX = getX();
    Tools::gotoxy(valueX, valueY);      printf(" ");
}
