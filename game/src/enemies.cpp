/**
 * @file
 * @brief     Enemies class
 * @copyright Diego SIERRA
 */

#include "enemies.h"

Enemies::Enemies()
{}

void Enemies::incNumAst() { ++m_numAst; }
void Enemies::incNumObst() { ++m_numObst; }
void Enemies::setNumAst(int numAst)   { m_numAst = numAst; }
void Enemies::setNumObst(int numObst) { m_numObst = numObst; }
int Enemies::getNumAst() const  { return m_numAst; }
int Enemies::getNumObst() const { return m_numObst; }

Asteroid *Enemies::createAsteroid(std::vector<int> params)
{
    int x = rand()%X_LIMIT + 3;
    Asteroid *ast {nullptr};

    if(x > X_LIMIT) {   x = X_LIMIT;    }

    if(params[NUMB_OBSTACLES] == 1)
    {
        ast = new Asteroid(x, 3, 100, 20, 100);
    }
    else if(params[NUMB_OBSTACLES] == 2)
    {
        ast = new Asteroid(x, 3, 200, 20, 200);
    }
    else
    {
        ast = new Asteroid(x, 3, params[HEALTH_ASTEROID], params[SPEED_ASTEROID], params[SIZE_ASTEROID]);
    }

    return ast;
}

void Enemies::setNumEnemies(int numAst = 0, int numObst = 0)
{
    m_numAst = numAst;
    m_numObst = numObst;
}
