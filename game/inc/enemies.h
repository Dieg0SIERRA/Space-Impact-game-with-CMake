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

    virtual Asteroid *createAsteroid(std::vector<int> params) override;
    //virtual Obstacle *createObstacle() override;
    //TODO: implement the other types of enemies

    void incNumAst();
    void setNumAst(int numAst);
    void setNumObst(int numObst);
    int getNumAst() const;
    int getNumObst() const;
    void setNumEnemies(int numAst, int numObst);

private:
    VECT_Asteroid ast;
    int m_numAst{2};
    int m_numObst{0};
};

#endif
