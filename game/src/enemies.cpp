/**
 * @file
 * @brief     Bullet class
 * @copyright Diego SIERRA
 */

#include "enemies.h"

Enemies::Enemies()
: m_numAst(2)
{
}

void Enemies::setNumAst(int numAst) { m_numAst = numAst; }
void Enemies::setNumObst(int numObst) { m_numObst = numObst; }
int Enemies::getNumAst() const { return m_numAst; }
int Enemies::getNumObst() const { return m_numObst; }

Asteroid *Enemies::createAsteroid(){
    Asteroid *ast = new Asteroid(rand()%X_LIMIT+3, 3);
    return ast;
}

void Enemies::setNumEnemies(int numAst = 0, int numObst = 0) {
    m_numAst = numAst;
    m_numObst = numObst;
}
