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

using VECT_Bullet = std::vector<Bullet>;
using VECT_PtrGameObj = std::vector<GameObject*>;
using MTX_GameObj = std::vector<std::vector<GameObject*>>;

class Game
{
public:
    Game();
    ~Game() = default;

    void upLevel();
    void setKey(int value);
    void setGameOver(bool value);
    void setCtrlSpeedAstLevel(uint8_t value);
    int  getKey() const;
    bool getGameOver() const;
    uint8_t getLevel() const;
    uint8_t getCtrlSpeedAstLevel() const;

    void run();
    void initGame();
    void update();
    void drawGameObjects();
    void initGameObjVect();
    void updateKey();
    void moveGameObjects();
    void timeWait(long fps);
    void ctrlSpeedAst();
    void manageBullets();
    void updateGameObjects(Collision status);
    Collision collisionDetector();
    void level();
    void updateLevelObj();

private:
    Screen    *m_display;
    Enemies   *m_enemis;
    Spaceship *m_ship;
    Bullet    *m_bullets;
    MTX_GameObj m_gameObjMatrix;

    int m_key{};
    bool m_gameOver{false};
    uint8_t m_levelGame{1};
    uint8_t m_ctrlSpeedAstLevel{ASTEROID_SPEED};
};

#endif
