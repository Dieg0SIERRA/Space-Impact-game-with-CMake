/**
 * @file
 * @brief     Main program.
 * @copyright Diego SIERRA
 */

#include "asteroid.h"
#include "gameObject.h"
#include "bullet.h"
#include "screen.h"
#include "spaceShip.h"
#include "game.h"
#include "tools.h"

Collision collision(class Spaceship& ship, class Bullet& bullet, class Asteroid& asteroid);

int main()
{
    Game game;

    game.run();
    
    return 0;
}
