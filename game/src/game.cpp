/**
 * @file
 * @brief     Tools class
 * @copyright Diego SIERRA
 */

#include "game.h"
#include "difficultyLevel.h"


Game::Game() 
    : m_levelGame(1), m_display(new Screen()), m_enemis(new Enemies()), m_ship(new Spaceship()), m_gameOver (false), m_ctrlSpeedAstLevel(ASTEROID_SPEED){
    Tools::hideCursor();
    srand(time(0));

    m_display->homeScreen();

    //TODO: create the m_level link
    //m_level = new Level();
    //m_level->init();
}

void Game::upLevel()               { ++m_levelGame; }
void Game::setKey(int value)       { m_key = value; }
void Game::setGameOver(bool value) { m_gameOver = value; }
int  Game::getKey() const          { return m_key; }
bool Game::getGameOver() const     { return m_gameOver; }
uint8_t Game::getLevel() const     { return m_levelGame; }
uint8_t Game::getCtrlSpeedAstLevel() const { return m_ctrlSpeedAstLevel; }
void Game::setCtrlSpeedAstLevel(uint8_t value) { m_ctrlSpeedAstLevel = value; }

void Game::timeWait(long fps)      {Tools::timeWait(fps); }

void Game::run() {
    // TODO:initialise game by pressing the up or down key and then enter for the first level.
    initGame();

    do {
        update();        
        //Sleep(20);
        level();
        timeWait(FPS_120);
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
        gameObj.push_back(m_enemis->createAsteroid(matrixEnemies[0]));  /* Creating a enemies */
    }
    m_gameObjMatrix.push_back(gameObj);
    
    /*Initializing bullets in the game objects matrix*/
    gameObj.clear();
    gameObj.push_back(m_bullets->createBullet(1, 1));
    m_gameObjMatrix.push_back(gameObj);
}

void Game::update() {
    updateKey();
    manageBullets();
    updateGameObjects(collisionDetector());
    moveGameObjects();
    drawGameObjects();
    
    //for (size_t i = 0; i < m_enemis->getNumAst(); ++i) {
    //    Asteroid *obj = dynamic_cast<Asteroid *>(m_gameObjMatrix[1][i]);
//
    //    Tools::gotoxy(107, 5+i);  std::cout<<"speed:       ";
    //    Tools::gotoxy(107, 5+i);  std::cout<<"speed: " << obj->getSpeed();
    //    
    //}

    ctrlSpeedAst();
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
        if(obj->getSpeed() == 0) {  
            obj->setSpeed(getCtrlSpeedAstLevel());  
            
            uint8_t speed = obj->getSpeed();
            Tools::gotoxy(107, 5+i);  std::cout<<"speed:       ";
            Tools::gotoxy(107, 5+i);  printf("speed: %d", speed);
        }
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
        m_gameObjMatrix[1].push_back(m_enemis->createAsteroid(matrixEnemies[getLevel()]));
    }
    else if (status == Collision::Spaceship_impacted) {
        shipObj->setHealth('-');
        m_display->modifHealth('-');
        m_gameObjMatrix[1].push_back(m_enemis->createAsteroid(matrixEnemies[getLevel()]));

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

void Game::level()
{
    int _score = m_display->getScore();
    int level = getLevel();


    /*
    if vector[level][score] >= score
        updateLevel()
    __________________________________
    En ctrlSpeedAst(): -> hay q meter varion ciclos 'for' para afectar diff speeds de los diff ast

    En updateGameObjects(): -> hay q condicionar cada 'if' para recuperar el tipo de ast y asi 
                               poder crear uno del mismo tipo

    modificar el constructor de Ast para pasarle tambien la Health del Ast
    
    */
    
    if(score == 10 && getLevel() == 1) {
        upLevel();
        updateLevelObj();
    }
    else if(score == 20 && getLevel() == 2) {
        upLevel();
        updateLevelObj();
    }
    else if(score == 30 && getLevel() == 3) {
        upLevel();
        updateLevelObj();
    }
    else if(score == 40 && getLevel() == 4) {
        upLevel();
        m_display->levelUp(getLevel());
        setCtrlSpeedAstLevel(14);

        m_enemis->setNumEnemies(4, 0);                      // adding 1 enemies, 0 obstacles 
        for(int i = 0; i < 4; ++i) 
            m_gameObjMatrix[1].push_back(m_enemis->createAsteroid(matrixEnemies[level]));
    }
    Tools::gotoxy(107, 10);  std::cout<<"Level:       ";
    Tools::gotoxy(107, 10);  printf("upLevel: %d", getLevel());
}

void Game::updateLevelObj()
{
    //if(getLevel() == 2 || getLevel() == 3){
    //    setCtrlSpeedAstLevel(getCtrlSpeedAstLevel() - 5);
    //}
    m_display->levelUp(getLevel());
    setCtrlSpeedAstLevel(getCtrlSpeedAstLevel() - 5);
}
