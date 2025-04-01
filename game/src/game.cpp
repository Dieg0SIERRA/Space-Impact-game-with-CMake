/**
 * @file
 * @brief     Game class
 * @copyright Diego SIERRA
 */

#include "game.h"
#include "difficultyLevel.h"


Game::Game() 
    : m_display(new Screen()), m_enemis(new Enemies()), m_ship(new Spaceship())
{
    std::random_device rd;          // To generate random numbers
    std::mt19937 gen(rd());

    Tools::hideCursor();
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

void Game::run()
{
    // TODO:initialise game by pressing the up or down key and then enter for the first level.
    initGame();
    do {
        update();
        level();
        timeWait(FPS_120);
    } while (getKey() != ESC && getGameOver() == false);

    if(getGameOver() == true) {
        m_display->endScreen();
    }    
}

void Game::initGame()
{
    int touch{};
    bool validKey{false};
    
    // TODO: implement options 'q' and 'l'.
    while(validKey == false)
    {
        touch = Tools::getKey();
        if(touch == 'l' || touch == 'p')
        {
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
    VECT_PtrGameObj gameObj{};              
    
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
    for (int i = 0; i < m_enemis->getNumAst(); ++i)
    {
        Asteroid *obj = dynamic_cast<Asteroid *>(m_gameObjMatrix[1][i]);
        obj->downSpeed();
        if(obj->getSpeed() == 0) {  
            obj->setSpeed(getCtrlSpeedAstLevel());
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
    size_t numAst = m_gameObjMatrix[1].size();
    size_t numbul = m_gameObjMatrix[2].size();
    
    for(size_t j = 0; j < numAst; ++j)
    {
        auto* asteroid = m_gameObjMatrix[1][j];
        int astX = asteroid->getX();
        int astY = asteroid->getY();

        for(size_t i=0; i<numbul; ++i)
        {
            auto* bullet = m_gameObjMatrix[2][i];
            auto spaceShipX = m_gameObjMatrix[0][0]->getX();
            auto spaceShipY = m_gameObjMatrix[0][0]->getY();

            //if(m_gameObjMatrix[1][j]->getX() == m_gameObjMatrix[2][i]->getX() && m_gameObjMatrix[1][j]->getY() == m_gameObjMatrix[2][i]->getY())
            if(astX == bullet->getX() && astY == bullet->getY())
            {
                asteroid->erase();
                asteroid->setY(0);
                bullet->erase();
                bullet->setY(0);
                result = Collision::Asteroid_Destroyed;
                break;
            }
            if(astX == spaceShipX   && astY == spaceShipY   ||
                    astX == spaceShipX+1 && astY == spaceShipY+1 ||
                    astX == spaceShipX+2 && astY == spaceShipY+2 ||
                    astX == spaceShipX-1 && astY == spaceShipY+1 ||
                    astX == spaceShipX-2 && astY == spaceShipY+1 )
            {
                asteroid->erase();
                asteroid->setY(0);
                result = Collision::Spaceship_impacted;
                break;
            }
        }
    }
    return result;
}

void Game::updateGameObjects(Collision status)
{
    // TODO: to improve this, it would be possible to eliminate the casting.
    auto *shipObj = dynamic_cast<Spaceship *>(m_gameObjMatrix[0][0]);

    if (status == Collision::Asteroid_Destroyed)
    {
        m_display->modifScore(POINT);
        m_gameObjMatrix[1].push_back(m_enemis->createAsteroid(matrixEnemies[0]));
    }
    else if (status == Collision::Spaceship_impacted)
    {
        shipObj->setHealth('-');
        m_display->modifHealth('-');
        m_gameObjMatrix[1].push_back(m_enemis->createAsteroid(matrixEnemies[0]));

        if(shipObj->getHealth() == 0)
        {
            shipObj->setLifes('-');
            shipObj->setHealth('s');
            shipObj->animationShipDie();
            m_display->resetHealth();

            if(shipObj->getLifes() == 0){
                setGameOver(true);
            }
        }
    }

    size_t size = m_gameObjMatrix[1].size();

    for(size_t i=0; i<size; ++i) {
        if(m_gameObjMatrix[1][i]->getY() == 0)
        {
            m_gameObjMatrix[1].erase(m_gameObjMatrix[1].begin() + i);
            --size;
            --i;
        }
    }

    size = m_gameObjMatrix[2].size();
    for(size_t i=0; i<size; ++i) {
        if(m_gameObjMatrix[2][i]->getY() == 0)
        {
            m_gameObjMatrix[2].erase(m_gameObjMatrix[2].begin() + i);
            --size;
            --i;
        }
    }
}

void Game::level()
{
    Tools::gotoxy(107, 31);  std::cout<<"asteroides : " << m_gameObjMatrix[1].size();
    int _score = m_display->getScore();
    const int currentLevel = getLevel();



    /*
    if vector[level][score] >= score
        updateLevel()
    __________________________________
    En ctrlSpeedAst(): -> hay q meter varion ciclos 'for' para afectar diff speeds de los diff ast

    En updateGameObjects(): -> hay q condicionar cada 'if' para recuperar el tipo de ast y asi 
                               poder crear uno del mismo tipo

    modificar el constructor de Ast para pasarle tambien la Health del Ast
    
    */

    if(_score == currentLevel * 10)
    {
        upLevel();
        m_display->levelUp(getLevel());
    }
    if(currentLevel >= 2 && currentLevel <= 6 && m_enemis->getNumAst() == currentLevel)
    {
        m_enemis->incNumAst();
        m_gameObjMatrix[1].push_back(m_enemis->createAsteroid(matrixEnemies[0]));
        setCtrlSpeedAstLevel(getCtrlSpeedAstLevel() - 2);
    }
    if(currentLevel > 7 && currentLevel <= 10 && currentLevel == m_count)
    {
        setCtrlSpeedAstLevel(getCtrlSpeedAstLevel() - 1);
        ++m_count;
    }
    if(currentLevel == 11 && currentLevel == m_count)
    {
        setCtrlSpeedAstLevel(getCtrlSpeedAstLevel() - 1);
        ++m_count;
    }
    if(currentLevel > 11 && currentLevel <= 15 && currentLevel == m_count)
    {
        m_enemis->incNumObst();
        setCtrlSpeedAstLevel(getCtrlSpeedAstLevel() - 1);
        ++m_count;
    }
    Tools::gotoxy(107, 20); std::cout << "                   ";
    Tools::gotoxy(107, 20); printf("new speed: %d", getCtrlSpeedAstLevel());
}
