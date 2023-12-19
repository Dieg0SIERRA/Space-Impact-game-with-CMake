/**
 * @file
 * @brief     Tools class
 * @copyright Diego SIERRA
 */

#include "game.h"

Game::Game() 
    : m_level(1), m_display(new Screen()), m_enemis(new Enemies()), m_ship(new Spaceship()), m_gameOver (false){
    Tools::hideCursor();
    srand(time(0));

    m_display->homeScreen();

    //TODO: create the m_level link
    //m_level = new Level();
    //m_level->init();
}

void Game::setLevel(uint8_t value) { m_level = value; }
void Game::setKey(int value)       { m_key = value; }
void Game::setGameOver(bool value) { m_gameOver = value; }
int  Game::getKey() const          { return m_key; }
bool Game::getGameOver() const     { return m_gameOver; }
uint8_t Game::getLevel() const     { return m_level; }

void Game::run() {
    // TODO:initialise game by pressing the up or down key and then enter for the first level.
    initGame();

    do {
        update();        
        Sleep(20);
        //timeWait();
    } while (getKey() != ESC && getGameOver() == false);

    if(getGameOver() == true) {
        m_display->endScreen();
    }    
}

void Game::initGame() {
    int touch;
    bool validKey = false;
    
    // TODO: implement options 'q' and 'l'.
    while(validKey == false){
        touch = Tools::getKey();
        if(touch == 'l' || touch == 'p') {
            system("cls");
            m_display->limits();
            validKey = true;
        }
        else if(touch == ESC)   {validKey = true;}
    }
    //TODO: perhaps it is better to create a player class that has a ship and lives.

    initGameObjVect();
}

void Game::initGameObjVect() 
{
    VECT_PtrGameObj gameObj;              
    
    gameObj.push_back(m_ship);                          /* Adding ship to game object matrix */
    m_gameObjMatrix.push_back(gameObj);

    gameObj.clear();
    m_enemis->setNumEnemies(2, 0);                      /* starting with 2 enemies, 0 obstacles */
    for(int i = 0; i < m_enemis->getNumAst(); ++i) {
        gameObj.push_back(m_enemis->createAsteroid());  /* Creating a enemies */
    }
    m_gameObjMatrix.push_back(gameObj);
    
    /*Initializing bullets in the game objects matrix*/
    gameObj.clear();
    gameObj.push_back(m_bullets->createBullet(1, 1));
    m_gameObjMatrix.push_back(gameObj);
}

void Game::update() {
    updateKey();
    ctrlSpeedAst();
    manageBullets();
    updateGameObjects(collisionDetector());
    moveGameObjects();
    drawGameObjects();    
}

void Game::updateKey()
{
    int directionKey = Tools::getKey();
    Spaceship *shipObj = dynamic_cast<Spaceship *>(m_gameObjMatrix[0][0]);

    setKey(directionKey);
    shipObj->setKeyDirection(directionKey);
}

void Game::ctrlSpeedAst()
{
    for (size_t i = 0; i < m_enemis->getNumAst(); ++i) {
        Asteroid *obj = dynamic_cast<Asteroid *>(m_gameObjMatrix[1][i]);
        //if(obj == nullptr)  { obj->downSpeed();   }
        obj->downSpeed();
    }
}

void Game::manageBullets()
{
    if(getKey() == 'b') {
        m_gameObjMatrix[2].push_back(m_bullets->createBullet(m_gameObjMatrix[0][0]->getX(), m_gameObjMatrix[0][0]->getY()));
    }
}

void Game::moveGameObjects()
{
    for(int i=0; i<3; ++i) {
        for(int j=0; j<m_gameObjMatrix[i].size(); ++j) {
            m_gameObjMatrix[i][j]->move();
        }
    }
}

void Game::drawGameObjects()
{    
    //TODO: improve this, it's just an idea
    for(int i=0; i<m_gameObjMatrix.size(); ++i) {
        for(int j=0; j<m_gameObjMatrix[i].size(); ++j) {
            m_gameObjMatrix[i][j]->draw();
        }
    }
    m_display->printStatusBar();
}

void Game::timeWait() {
   static long   t = clock();
   const float fps = 60.0f;

   long toWait = t + CLOCKS_PER_SEC / fps - clock();
   if (toWait > 0)  {   Sleep(toWait/1000);   }      

   t = clock();
}

Collision Game::collisionDetector()
{
    Collision result = Collision::NONE;
    int numAst = m_gameObjMatrix[1].size();
    int numbul = m_gameObjMatrix[2].size();

    int ast_x = m_gameObjMatrix[1][0]->getX();
    int bul_x = m_gameObjMatrix[2][0]->getX();
    int bul_y = m_gameObjMatrix[2][0]->getY();
    
    for(int j = 0; j < numAst; ++j){
        for(int i=0; i<numbul; ++i){
            if(m_gameObjMatrix[1][j]->getX() == m_gameObjMatrix[2][i]->getX() && m_gameObjMatrix[1][j]->getY() == m_gameObjMatrix[2][i]->getY()){
                m_gameObjMatrix[1][j]->erase();
                m_gameObjMatrix[1][j]->setY(0);                
                m_gameObjMatrix[2][i]->erase();
                m_gameObjMatrix[2][i]->setY(0);
                result = Collision::Asteroid_Destroyed;
            }
            else if(m_gameObjMatrix[1][j]->getX() == m_gameObjMatrix[0][0]->getX() && m_gameObjMatrix[1][j]->getY() == m_gameObjMatrix[0][0]->getY()){
                m_gameObjMatrix[1][j]->erase();
                m_gameObjMatrix[1][j]->setY(0);
                result = Collision::Spaceship_impacted;
            }
        }
    }
    return result;
}

void Game::updateGameObjects(Collision status)
{
    // TODO: to improve this, it would be possible to eliminate the casting.
    Spaceship *shipObj = dynamic_cast<Spaceship *>(m_gameObjMatrix[0][0]);

    if (status == Collision::Asteroid_Destroyed) {
        m_display->modifScore(POINT);
        m_gameObjMatrix[1].push_back(m_enemis->createAsteroid());
    }
    else if (status == Collision::Spaceship_impacted) {
        shipObj->setHealth('-');
        m_display->modifHealth('-');
        m_gameObjMatrix[1].push_back(m_enemis->createAsteroid());

        if(shipObj->getHealth() == 0) {
            shipObj->setLifes('-');
            shipObj->setHealth('s');
            shipObj->animationShipDie();
            m_display->resetHealth();

            if(shipObj->getLifes() == 0) {
                setGameOver(true);
                
            }
        }
    }

    int size = m_gameObjMatrix[1].size();

    for(int i=0; i<size; ++i) {
        if(m_gameObjMatrix[1][i]->getY() == 0) {
            m_gameObjMatrix[1].erase(m_gameObjMatrix[1].begin() + i);
            --size;
            --i;
        }
    }

    size = m_gameObjMatrix[2].size();
    for(int i=0; i<size; ++i) {
        if(m_gameObjMatrix[2][i]->getY() == 0) {
            m_gameObjMatrix[2].erase(m_gameObjMatrix[2].begin() + i);
            --size;
            --i;
        }
    }
}
