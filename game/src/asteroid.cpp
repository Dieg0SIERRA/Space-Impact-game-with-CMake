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
    if (m_size == 10)     // 10 shoots to kill
    {
        if(valueY > 3) {
            if (valueY > 4)
            {
                Tools::gotoxy(valueX, valueY-1);    printf("%c%c", 220, 220);
            }
            Tools::gotoxy(valueX, valueY);    printf("%c%c", 223, 223);
        }
    }
    if (m_size == 20)     // 10 shoots to kill
    {
        if(valueY > 3) {
            if (valueY > 4 && valueY < Y_LIMIT)
            {
                Tools::gotoxy(valueX-1, valueY-1);    printf("%c%c%c", 250, 47, 250);
                Tools::gotoxy(valueX-1, valueY+1);    printf("%c%c%c", 250, 92, 250);
            }
            else if (valueY == Y_LIMIT)
            {
                Tools::gotoxy(valueX-1, valueY-1);    printf("%c%c%c", 250, 47, 250);
            }
            Tools::gotoxy(valueX-1, valueY);    printf("%c%c%c", 45, 157, 45);
        }
    }
    if (m_size == 100)     // It's an obstacle, it can not be shot
    {
        if(valueY > 3) {
            if (valueY > 4 && valueY < Y_LIMIT)
            {
                Tools::gotoxy(valueX, valueY-1);    printf("%c%c", 201, 187);
                Tools::gotoxy(valueX, valueY+1);    printf("%c%c", 200, 188);
            }
            else if (valueY == Y_LIMIT)
            {
                Tools::gotoxy(valueX, valueY-1);    printf("%c%c", 201, 187);
            }
            Tools::gotoxy(valueX, valueY);    printf("%c%c", 186, 186);
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
                if (m_size == 10)
                {
                    if (valueY > 4)
                    {
                        Tools::gotoxy(valueX, valueY-1);      printf("  ");
                    }
                    Tools::gotoxy(valueX, valueY);      printf("  ");
                }
                else if (m_size == 20)
                {
                    if (valueY > 4 && valueY < Y_LIMIT)
                    {
                        Tools::gotoxy(valueX-1, valueY-1);      printf("   ");
                        Tools::gotoxy(valueX-1, valueY+1);      printf("   ");
                    }
                    else if (valueY == Y_LIMIT)
                    {
                        Tools::gotoxy(valueX-1, valueY-1);      printf("   ");
                    }
                    Tools::gotoxy(valueX-1, valueY);      printf("   ");
                }
                else if (m_size == 100)
                {
                    if (valueY > 4 && valueY < Y_LIMIT)
                    {
                        Tools::gotoxy(valueX, valueY-1);      printf("  ");
                        Tools::gotoxy(valueX, valueY+1);      printf("  ");
                    }
                    else if (valueY == Y_LIMIT)
                    {
                        Tools::gotoxy(valueX, valueY-1);      printf("  ");
                    }
                    Tools::gotoxy(valueX, valueY);      printf("  ");
                }
                else
                {
                    Tools::gotoxy(valueX, valueY);      printf(" ");
                }
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

    if (m_size == 10)
    {
        if (valueY > 4)
        {
            Tools::gotoxy(valueX, valueY-1);      printf("  ");
        }
        Tools::gotoxy(valueX, valueY);      printf("  ");
    }
    else if (m_size == 20)
    {
        if (valueY > 4)
        {
            Tools::gotoxy(valueX-1, valueY-1);      printf("   ");
            Tools::gotoxy(valueX-1, valueY+1);      printf("   ");
        }
        Tools::gotoxy(valueX-1, valueY);      printf("   ");
    }
    else if (m_size == 100)
    {
        if (valueY > 4)
        {
            Tools::gotoxy(valueX, valueY-1);      printf("  ");
            Tools::gotoxy(valueX, valueY+1);      printf("  ");
        }
        Tools::gotoxy(valueX, valueY);      printf("  ");
    }
    else
    {
        Tools::gotoxy(valueX, valueY);      printf(" ");
    }
}
