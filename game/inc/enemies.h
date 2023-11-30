/**
 * @file
 * @brief     Enemies class
 * @copyright Diego SIERRA
 */

#ifndef ENEMIES_H
#define ENEMIES_H

#include "factoryEnemies.h"

class Enemies : public FactoryEnemies 
{
public:
    Enemies();
    ~Enemies() = default;

    virtual void createAsteroid() override;

    void setNumAst(int numAst);
    int getNumAst() const;
    //virtual Obstacle *createObstacle() override;
    //TODO: implementar los otros tipos de enemigos

private:
    VECT_Asteroid ast;
    int m_numAst = 0;
};

#endif
