/**
 * @file
 * @brief     Tools class
 * @copyright Diego SIERRA
 */

#include "game.h"

Game::Game() 
    : m_level(1), m_display(new Screen()), m_ship(new Spaceship()), m_enemis(new Enemies()) {
    hideCursor();
    srand(time(0));

    //m_display->init();
    m_display->homeScreen();

    //TODO: crear el vinculo de m_level
    //m_level = new Level();
    //m_level->init();
}

void Game::setLevel(uint8_t value) { m_level = value; }
uint8_t Game::getLevel() const     { return m_level; }

void Game::run() {
    // TODO:inicializar juego pidiendo la tecla de arriba o abajo y luego enter para el primer nivel
    initGame();

    int counter = 0;

    do {
        update();
        draw();
        //counter++;
        Sleep(1);
        /* Continuar con el codigo */
        //TODO: implementar metodo draw
    } while (counter<100);
}

void Game::initGame() {
    char touch;
    bool validKey = false;
    
    // TODO: implementar las opciones 'q' y 'l'
    while(validKey == false){
        touch = getKey();
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
    moveGameObjects();
}

void Game::moveGameObjects() {
    // TODO: implementar el update
    for (auto& gameObject : m_gameObjects) {
        gameObject->move();
    }
}

void Game::draw() {    
    //TODO: mejorar esto, es solo una idea
    m_display->printStatusBar();
    for (auto& gameObject : m_gameObjects) {
        gameObject->draw();
    }
}
