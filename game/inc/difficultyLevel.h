/**
 * @file
 * @brief     management of the enemies quantity 
 * @copyright Diego SIERRA
 * @ 
 * The matrix is composed of 3 columns 
 * [lvl][num_ast][health_ast][speed_ast]
 * Each row is a level
 */

#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "tools.h"

#define MAX_LEVELS 10

using MATRIX_Vect = std::vector <std::vector<int>> ;

//TODO: should reserve space for the matrix (vector)

                         // score | # Ast_1 | hp_1 | spd_1 | # Ast_2 | hp_2 | spd_2 | # Ast_3 | hp_3 | spd_3 | # obst | spd_obst 

std::vector <std::vector<int>> matrixEnemies = {{10,      1,       1,     26,      0,       0,     0,        0,       0,     0,      0,      0},
                             {20,      2,       1,     23,      0,       0,     0,        0,       0,     0,      0,      0},
                             {30,      3,       1,     20,      0,       0,     0,        0,       0,     0,      0,      0},
                             {45,      4,       1,     20,      0,       0,     0,        0,       0,     0,      0,      0},
                             {60,      5,       1,     17,      0,       0,     0,        0,       0,     0,      0,      0},
                             {80,      6,       1,     17,      0,       0,     0,        0,       0,     0,      0,      0},
                             {100,     7,       1,     17,      0,       0,     0,        0,       0,     0,      0,      0},
                             {120,     7,       1,     14,      1,       2,     17,       0,       0,     0,      0,      0},
                             {140,     7,       1,     14,      2,       2,     17,       0,       0,     0,      0,      0},
                             {160,     7,       1,     14,      3,       2,     17,       0,       0,     0,      0,      0},
                             {190,     5,       1,     14,      5,       2,     17,       0,       0,     0,      0,      0},
                             {220,     2,       1,     14,      8,       2,     17,       0,       0,     0,      0,      0},
                             {250,     0,       0,     0,       10,      2,     17,       0,       0,     0,      0,      0},
                             {280,     0,       0,     14,      10,      2,     17,       1,       3,    17,      0,      0},
                             {310,     0,       0,     0,       8,       2,     14,       3,       3,    17,      0,      0},
                             {440,     0,       0,     0,       5,       2,     14,       6,       3,    17,      0,      0},
                             {370,     0,       0,     0,       5,       2,     11,       7,       3,    14,      0,      0},
                             {400,     0,       0,     0,       5,       2,     11,       7,       3,    14,      1,      17},
                             {450,     0,       0,     0,       4,       2,     11,       8,       3,    14,      3,      14},
                             {500,     0,       0,     0,       4,       2,     10,       8,       3,    14,      5,      11} };
                 
#endif
