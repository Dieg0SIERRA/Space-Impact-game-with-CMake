/**
 * @file
 * @brief     Tools class
 * @copyright Diego SIERRA
 */

#include "game.h"

Game::Game() {
    hideCursor();
    srand(time(0));

    m_display = new Screen();
    m_ship    = new Spaceship();
    m_enemis  = new Enemies();
    //m_display->init();
    m_display->homeScreen();
    m_enemis->createAsteroid();
    

    //TODO: crear el vinculo de m_level
    //m_level = new Level();
    //m_level->init();
}

void Game::run() {
    // TODO:inicializar juego pidiendo la tecla de arriba o abajo y luego enter para el primer nivel
    initGame();

    bool temp = true;

    do {
        update();
        temp = false;
        /* Continuar con el codigo */
        //TODO: implementar metodo draw
    } while (temp);
    
    update();
    
    
}

void Game::initGame() {
    char touch;
    bool validKey = false;
    
    while(validKey == false){
        touch = getKey();
        if(touch == 'l' || touch == 'p') {
            system("cls");
            m_display->limits();
            validKey = true;
        }
        else if(touch == 'q')   {validKey = true;}
    }

    // TODO: implementar las opciones 'q' y 'l'
}

void Game::update() {
    // TODO: implementar el update
    m_display->printStatusBar();
}

void Game::draw() {
    // TODO: implementar el draw
    m_ship->draw(X_init, Y_init);       //TODO: mejorar esto, es solo una idea
}
