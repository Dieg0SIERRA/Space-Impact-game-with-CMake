/**
 * @file
 * @brief     Main program.
 * @copyright Diego SIERRA
 */


#include "asteroid.h"
#include "basicElement.h"
#include "bullet.h"
#include "screen.h"
#include "spaceShip.h"
#include "tools.h"
#include "animations.h"

using VECT_Asteroid = std::vector<Asteroid>;
using VECT_Bullet = std::vector<Bullet>;

Collision collision(class Spaceship& ship, class Bullet& bullet, class Asteroid& asteroid);

int main()
{
    bool game_over = false;
    char touch = ' ';
    int countAst;
    int countBullet;
    int astSpeed = 1;

    hideCursor();
    system("cls");
    system("Color 0A");
    srand(time(0));

    Screen display;
    Spaceship ship;
    VECT_Bullet bullets;
    VECT_Asteroid ast;

    display.printScreen(ALL);
    display.limits();    
    ship.draw();

    for(int i = 0; i < 3; i++) {
        ast.push_back(Asteroid(rand()%LIM_RIGHT+3, 3));
    }

    while(!game_over)
    {
        countAst = 0;
        countBullet = 0;

        if (kbhit())
        {
            touch = getch();
            if(touch == 'b') {
                bullets.push_back(Bullet(ship.getX()+2, ship.getY()-1));
            }
        }

        for(Bullet& bullet : bullets) {
            bool bulletOut = bullet.move();
            if (bulletOut) {
                bullet.erase(bullet.getX(), bullet.getY());
            }
        }

        if(astSpeed > 15)
        {
            for(Asteroid& asteroid : ast)
            {
                asteroid.move();
                astSpeed = 0;
            }
        }
        else    ++astSpeed;
        
        for(Asteroid& asteroid : ast)
        {
            for(Bullet& bullet : bullets)
            {
                Collision result = collision(ship, bullet, asteroid);

                if(result == Asteroid_Destroyed) {
                    bullets.erase(bullets.begin() + countBullet);
                    ast.erase(ast.begin() + countAst);
                    ast.push_back(Asteroid(rand()%75+3, 4));
                    display.modifScore(POINT);
                    ++countBullet;
                }
                else if(result == Spaceship_impacted) {
                    ship.setHealth('-');
                    display.modifHealth('-');
                    display.printScreen(HEALTH);
                    ast.erase(ast.begin() + countAst);
                    ast.push_back(Asteroid(rand()%LIM_RIGHT+3, 4));
                }

                if(ship.getHealth() == 0) {
                    ship.animationShipDie();
                    ship.setLifes('-');
                    ship.setHealth('s');
                    auto start = std::chrono::system_clock::now();
                    display.healthToZero();
                    auto end = std::chrono::system_clock::now();
                    std::chrono::duration<float,std::milli> duration = end - start;
                    gotoxy(5, 34);
                    std::cout << "Tiempo de ejecucion " << duration.count() << " segundos." << std::endl;

                    if(ship.getLifes() == 0) {
                        game_over = true;
                        display.printEnd();
                    } 
                }
            }
            ++countAst;
        }

        ship.move();
        Sleep(1);
    } 

    gotoxy(0, 2);
    for(auto it : gameOver)
    {
        std::cout << it << "\n";
    }
    gotoxy(15, 47); printf("You are a LOOOOOSER!!!!!");
    gotoxy(1, 48);

    return 0;
}

Collision collision(class Spaceship& ship, class Bullet& bullet, class Asteroid& asteroid)
{
    int xValueShip = ship.getX();
    int yValueShip = ship.getY();
    int xValueBullet = bullet.getX();
    int yValueBullet = bullet.getY();
    int xValueAsteroid = asteroid.getX();
    int yValueAsteroid = asteroid.getY();
    Collision result = NONE;

    if (xValueBullet == xValueAsteroid+1 && yValueBullet == yValueAsteroid)
    {
        result = Asteroid_Destroyed;
        bullet.erase(xValueBullet, yValueBullet);
        asteroid.erase(xValueAsteroid, yValueAsteroid);
    }

    else if(xValueAsteroid >= xValueShip-2 && xValueAsteroid < xValueShip+2 && yValueAsteroid >= yValueShip && yValueAsteroid <= yValueShip+2)
    {
        result = Spaceship_impacted;
        asteroid.erase(xValueAsteroid, yValueAsteroid);
    }
    return result;
}
