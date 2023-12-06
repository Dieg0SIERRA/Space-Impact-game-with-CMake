/**
 * @file
 * @brief     Tools class
 * @copyright Diego SIERRA
 */

#include "game.h"

Game::Game() 
    : m_level(1), m_display(new Screen()), m_ship(new Spaceship()), m_enemis(new Enemies()) {
    Tools::hideCursor();
    srand(time(0));

    //m_display->init();
    m_display->homeScreen();

    //TODO: crear el vinculo de m_level
    //m_level = new Level();
    //m_level->init();
}

void Game::setLevel(uint8_t value) { m_level = value; }
void Game::setKey(int value) { m_key = value; }
int  Game::getKey() const { return m_key; }
uint8_t Game::getLevel() const     { return m_level; }

void Game::run() {
    // TODO:inicializar juego pidiendo la tecla de arriba o abajo y luego enter para el primer nivel
    initGame();

    do {
        update();
        draw();
        Sleep(10);
        /* Continuar con el codigo */
        //TODO: implementar metodo draw
    } while (getKey() != ESC);
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
        else if(touch == 'q')   {validKey = true;}
    }
    //TODO: depronto es mejor crear una clase player que tenga una nave y las vidas
    
    m_ship->createShip();               // Creating a ship    
    m_enemis->setNumEnemies(2, 0);      // starting with 2 enemies, 0 obstacles

    initGameObjVect();
}

void Game::initGameObjVect() {
    m_gameObjects.push_back(m_ship);

    for(int i = 0; i < m_enemis->getNumAst(); ++i) {
        m_gameObjects.push_back(m_enemis->createAsteroid()); // Creating a enemies 
    }
}

void Game::update() {
    // TODO: implementar el update
    updateKey();
    ctrlSpeedAst();
    updateGameObjects();
}

void Game::updateGameObjects() {
    // TODO: implementar el update
    size_t size = m_gameObjects.size();
    for (size_t i = 0; i < size; ++i) {
        GameObject *obj = m_gameObjects[i];
        obj->move();

        // Check if game object has been removed
      // then go back 1 item (next item its at index i, not i+1)
        if (m_gameObjects.size() != size) {
            size = m_gameObjects.size();
            --i;
      }
    }
}

void Game::draw() {    
    //TODO: mejorar esto, es solo una idea
    m_display->printStatusBar();
    for (auto& gameObject : m_gameObjects) {
        gameObject->draw();
    }
}


void Game::updateKey() {

    int directionKey = Tools::getKey();
    setKey(directionKey);
    m_ship->setKeyDirection(directionKey);
}

void Game::ctrlSpeedAst(){

    for (size_t i = 1; i < m_enemis->getNumAst()+1; ++i) {
        Asteroid *obj = dynamic_cast<Asteroid *>(m_gameObjects[i]);
        if(obj == nullptr)  { obj->downSpeed();   }
    }
}
