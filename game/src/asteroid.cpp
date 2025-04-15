/**
 * @file
 * @brief     Asteroid class
 * @copyright Diego SIERRA
 */

#include "asteroid.h"

Asteroid::Asteroid(int x, int y, uint8_t health, uint8_t speed, uint8_t size)
{
    setX(x);
    setY(y);
    setSpeed(speed);
    setHealth(health);
    m_size = size;
}

void Asteroid::setSpeed(uint8_t speed) { m_speed = speed; }
void Asteroid::setSize(uint8_t size)   { m_speed = size; }

uint8_t Asteroid::getSpeed() const { return m_speed; }
uint8_t Asteroid::getSize() const  { return m_size; }
void Asteroid::downSpeed() { --m_speed; }

void Asteroid::draw() 
{
    int valueY = getY();
    int valueX = getX();

    // 220 = _, 223 = ¯, 169 = ®, 184 = ©, 176 = ¦, 177 = ¦, 178 = ¦, 219 = ¦

    if (m_size == 1)    // 1 shoot to kill
    {
        if(valueY > 3) {
            Tools::gotoxy(valueX, valueY);    printf("%c", 184);
        }
    }
    if (m_size == 2)    // 2 shoots to kill
    {
        if(valueY > 3) {
            Tools::gotoxy(valueX, valueY);    printf("%c", 176);
        }
    }
    if (m_size == 3)    // 3 shoots to kill
    {
        if(valueY > 3) {
            Tools::gotoxy(valueX, valueY);    printf("%c", 220);
        }
    }
    if (m_size == 4)    // 4 shoots to kill
    {
        if(valueY > 3) {
            Tools::gotoxy(valueX, valueY);    printf("%c", 178);
        }
    }
    if (m_size == 5)     // 5 shoots to kill
    {
        if(valueY > 3) {
            Tools::gotoxy(valueX, valueY);    printf("%c""%c", 176, 177);
            //Tools::gotoxy(valueX, valueY);    printf("%c""%c", 223, 223);
        }
    }
}

void Asteroid::move() 
{
    if(getSpeed() == 1)
    {
        int valueY = getY();
        int valueX = getX();

        if(valueY >= 3)
        {
            if (valueY > 3 && valueY <= Y_LIMIT) {
                Tools::gotoxy(valueX, valueY);      printf(" ");
            }
            if (valueY >= Y_LIMIT)
            {
                valueX = rand()%X_LIMIT + 3;
                if(valueX > X_LIMIT) {    valueX = X_LIMIT;    }
                valueY = 4;
            }
            else {  ++valueY;   }

            setY(valueY);
            setX(valueX);
        }
    }
}

void Asteroid::erase() 
{
    int valueY = getY();
    int valueX = getX();
    Tools::gotoxy(valueX, valueY);      printf(" ");
}
