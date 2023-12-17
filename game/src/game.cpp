/**
 * @file
 * @brief     Tools class
 * @copyright Diego SIERRA
 */

#include "game.h"

Game::Game() 
    : m_level(1), m_display(new Screen()), m_ship(new Spaceship()), m_enemis(new Enemies()), m_gameOver(false){
    Tools::hideCursor();
    srand(time(0));

    m_display->homeScreen();

    //TODO: crear el vinculo de m_level
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
    // TODO:inicializar juego pidiendo la tecla de arriba o abajo y luego enter para el primer nivel
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
    
    // TODO: implementar las opciones 'q' y 'l'
    while(validKey == false){
        touch = Tools::getKey();
        if(touch == 'l' || touch == 'p') {
            system("cls");
            m_display->limits();
            validKey = true;
        }
        else if(touch == ESC)   {validKey = true;}
    }
    //TODO: depronto es mejor crear una clase player que tenga una nave y las vidas
    
    m_ship->createShip();               // Creating a ship    
    m_enemis->setNumEnemies(2, 0);      // starting with 2 enemies, 0 obstacles

    initGameObjVect();
}

void Game::initGameObjVect() 
{
    //m_gameObjects.push_back(m_ship);
//
    //for(int i = 0; i < m_enemis->getNumAst(); ++i) {
    //    m_gameObjects.push_back(m_enemis->createAsteroid()); // Creating a enemies 
    //}


    VECT_PtrGameObj gameObj;
    gameObj.push_back(m_ship);
    m_gameObjMatrix.push_back(gameObj);

    gameObj.clear();
    for(int i = 0; i < m_enemis->getNumAst(); ++i) {
        gameObj.push_back(m_enemis->createAsteroid()); // Creating a enemies 
    }

    m_gameObjMatrix.push_back(gameObj);
    
    /*Initializing bullets in the game objects matrix*/
    gameObj.clear();
    gameObj.push_back(m_bullets->createBullet(1, 1));
    m_gameObjMatrix.push_back(gameObj);
}

void Game::update() {
    // TODO: implementar el update
    updateKey();
    ctrlSpeedAst();
    manageBullets();
    updateGameObjects(collisionDetector());
    moveGameObjects();
    drawGameObjects();    
}

void Game::updateKey() {

    int directionKey = Tools::getKey();
    setKey(directionKey);
    m_ship->setKeyDirection(directionKey);
}

void Game::ctrlSpeedAst(){

    for (size_t i = 0; i < m_enemis->getNumAst(); ++i) {
        //Asteroid *obj = dynamic_cast<Asteroid *>(m_gameObjects[i]);
        Asteroid *obj = dynamic_cast<Asteroid *>(m_gameObjMatrix[1][i]);
        //if(obj == nullptr)  { obj->downSpeed();   }
        obj->downSpeed();
    }
}

void Game::manageBullets(){

    if(getKey() == 'b') {
        //m_gameObjects.push_back(m_bullets->createBullet(m_ship->getX(), m_ship->getY()));
        m_gameObjMatrix[2].push_back(m_bullets->createBullet(m_ship->getX(), m_ship->getY()));
    }
}

void Game::moveGameObjects() {
    // TODO: implementar el update

    //for (auto& gameObject : m_gameObjects) {
    //    gameObject->move();
    //}

    //for(int i=0; i<3; ++i) {
    //    for(int j=0; j<m_gameObjMatrix[i].size(); ++j) {
    //        m_gameObjMatrix[i][j]->move();
    //    }
    //}

    VECT_PtrGameObj gameObj;
    for(int i=0; i<3; ++i) {
        for(int j=0; j<m_gameObjMatrix[i].size(); ++j) {
            m_gameObjMatrix[i][j]->move();
        }
    }

/*
    size_t size = m_gameObjects.size();
    for (size_t i = 0; i < size; ++i) {
        GameObject *obj = m_gameObjects[i];

        obj->move();
        //if(obj->getY() > 0) {   obj->move();    }
        //else {  m_gameObjects.erase(m_gameObjects.begin() + i);    }

        // Check if game object has been removed
        // then go back 1 item (next item its at index i, not i+1)
        if (m_gameObjects.size() != size) {
            size = m_gameObjects.size();
            --i;
        }
    }
*/
}

void Game::drawGameObjects() {    
    //TODO: mejorar esto, es solo una idea
    
    //for (auto& gameObject : m_gameObjects) {
    //    gameObject->draw();
    //}

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

/*
Collision Game::collisionDetector() {
    Collision result = Collision::NONE;
    size_t size = m_gameObjects.size();
    int columns = 2;
    int numAst = m_enemis->getNumAst();
    int numbul = m_gameObjects.size() - m_enemis->getNumAst() - 1;
    MATRIX_Vect AstPosition(numAst, std::vector<int>(2));
    MATRIX_Vect BulPosition(numbul, std::vector<int>(2));

    Tools::gotoxy(107, 5);  std::cout<<"Ast_1  in X : "<<m_gameObjects[1]->getX();
    Tools::gotoxy(107, 6);  std::cout<<"Ast_22 in X : "<<m_gameObjects[2]->getX();

    for (int ast = 1; ast <= numAst; ++ast) {
        for(int bul = numAst+1; bul < numbul; ++bul){
            Tools::gotoxy(107, 8);  std::cout<<"Bul in X : "<<m_gameObjects[bul]->getX();            

            if(m_gameObjects[ast]->getX() == m_gameObjects[bul]->getX() && m_gameObjects[ast]->getY() == m_gameObjects[bul]->getY()){
                //m_gameObjects.erase(m_gameObjects.begin() + bul);
                //m_gameObjects.erase(m_gameObjects.begin() + ast);
                m_gameObjects[ast]->setY(0);
                m_gameObjects[bul]->setY(0);
                m_gameObjects[ast]->erase();
                m_gameObjects[bul]->erase();
                
                result = Collision::Asteroid_Destroyed;
            }
        }
    }
    return result;
}
*/
Collision Game::collisionDetector() {
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

void Game::updateGameObjects(Collision status){

    //size_t size = m_gameObjects.size();

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
                Tools::gotoxy(107, 15);  std::cout<<"lifes : "<<shipObj->getLifes();
                setGameOver(true);
                
            }
        }
    }

    
    //for (size_t i = 0; i < size; ++i) {
    //    GameObject *obj = m_gameObjects[i];
//
    //    if(obj->getY() == 0) {  m_gameObjects.erase(m_gameObjects.begin() + i); }
    //    if (m_gameObjects.size() != size) {
    //        //size = m_gameObjects.size();
    //        --size;
    //        --i;
    //    }
    //}

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
