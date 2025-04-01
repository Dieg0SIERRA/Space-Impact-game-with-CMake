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
    ast = new Asteroid(x, 3, 1, 1);

    //if(params[Ast_hp_1] == 1) {
    //    ast = new Asteroid(x, 3, params[Ast_hp_1], params//[Ast_spd_1]);
    //}
    //else if(params[Ast_hp_2] == 2) {
    //    ast = new Asteroid(x, 3, params[Ast_hp_2], params//[Ast_spd_2]);
    //}
    //else if(params[Ast_hp_3] == 3) {
    //	ast = new Asteroid(x, 3, params[Ast_hp_2], params//[Ast_spd_2]);
    //}    

    return ast;
}

void Enemies::setNumEnemies(int numAst = 0, int numObst = 0)
{
    m_numAst = numAst;
    m_numObst = numObst;
}
