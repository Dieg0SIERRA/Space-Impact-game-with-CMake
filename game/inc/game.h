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
using VECT_PtrGameObj = std::vector<GameObject*>;

class Game
{
public:
    Game();
    ~Game() = default;

    void setLevel(uint8_t value);
    void setKey(int value);
    int  getKey() const;
    uint8_t getLevel() const;

    void run();
    void initGame();
    void update();
    void draw();
    void initGameObjVect();
    void updateKey();
    void updateGameObjects();
    void timeWait();
    void ctrlSpeedAst();

private:
    Screen *m_display;
    Spaceship *m_ship;
    Enemies *m_enemis;
    VECT_PtrGameObj m_gameObjects;

    int m_key;
    //Enemis *m_enemis;
    uint8_t m_level;
   
    VECT_Bullet m_bullets;
};


#endif
