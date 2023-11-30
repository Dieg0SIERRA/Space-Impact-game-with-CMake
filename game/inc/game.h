/**
 * @file
 * @brief     Game class
 * @copyright Diego SIERRA
 */

#ifndef GAME_H
#define GAME_H

#include "asteroid.h"
#include "gameObject.h"
#include "bullet.h"
#include "screen.h"
#include "spaceShip.h"
#include "enemies.h"
#include "tools.h"

//class Screen;


//using VECT_Asteroid = std::vector<Asteroid>;
using VECT_Bullet = std::vector<Bullet>;
using VECT_GameObject = std::vector<GameObject>;

class Game
{
public:
    Game();
    ~Game() = default;

    void run();
    void initGame();
    void update();
    void draw();

private:
    Screen *m_display;
    Spaceship *m_ship;
    Enemies *m_enemis;

    char m_key;
    //Enemis *m_enemis;
    //Level *m_level;
   
    VECT_Bullet m_bullets;
};


#endif
