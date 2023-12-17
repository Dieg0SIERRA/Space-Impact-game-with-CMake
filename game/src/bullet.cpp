/**
 * @file
 * @brief     Bullet class
 * @copyright Diego SIERRA
 */

#include "bullet.h"

Bullet::Bullet(int x, int y)
    :m_bulletOut(false)
{
    setX(x);
    setY(y);
}

void Bullet::setBulletOut(bool out) { m_bulletOut = out; }
bool Bullet::getBulletOut()  { return m_bulletOut; }

Bullet *Bullet::createBullet(int x, int y){
    Bullet *bullet = new Bullet(x, y);
    return bullet;
}

void Bullet::move()
{
    bool bulletOut = false;
    int valueY = getY();
    int valueX = getX();

    if(valueY > 3){
        Tools::gotoxy(valueX, valueY);      printf(" ");

        if (valueY > 4) {   setY(--valueY);  }
        else if (valueY == 4) {
            setBulletOut(true);
            setY(0);                // That's to avoid collision with asteroids
        }
    }
}

void Bullet::draw(){

    if(getBulletOut() == false) {
        int valueY = getY();
        int valueX = getX();

        if(valueY > 3) {
            Tools::gotoxy(valueX, valueY);
            printf("*");
        }
    }
}

void Bullet::erase() 
{
    int valueY = getY();
    int valueX = getX();
    Tools::gotoxy(valueX, valueY);      printf(" ");
}
