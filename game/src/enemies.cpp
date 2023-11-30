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
int Enemies::getNumAst() const { return m_numAst; }

void Enemies::createAsteroid(){
    for(int i = 0; i < m_numAst; ++i) {
        ast.push_back(Asteroid(rand()%LIM_RIGHT+3, 3));
    }
}
