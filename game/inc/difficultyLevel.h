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

enum matrixEnemies:int
{
    SCORE_LV        = 0,
    NUMB_ASTEROID      ,
    HEALTH_ASTEROID    ,
    SPEED_ASTEROID     ,
    NEW_NUMB_ASTEROID  ,
    NUMB_OBSTACLES     ,
    SPEED_OBSTACLES
};

//TODO: should reserve space for the matrix (vector)


inline std::vector <std::vector<int>> matrixEnemies =
    {                        // score   #_Ast_1   hp_1   spd_1   new_ast  #_Ast_2   hp_2   spd_2   #_Ast_3   hp_3   spd_3   #_obst   spd_obst
                             {0,       2,       1,     26,      2,       0,       0,     0,        0,       0,     0,      0,      0},
                             {10,      2,       1,     24,      3,       0,       0,     0,        0,       0,     0,      0,      0},
                             {20,      3,       1,     22,      4,       0,       0,     0,        0,       0,     0,      0,      0},
                             {30,      4,       1,     20,      5,       0,       0,     0,        0,       0,     0,      0,      0},
                             {40,      5,       1,     18,      6,       0,       0,     0,        0,       0,     0,      0,      0},
                             {50,      6,       1,     16,      7,       0,       0,     0,        0,       0,     0,      0,      0},
                             {60,      6,       1,     14,      7,       0,       0,     0,        0,       0,     0,      0,      0},
                             {70,      6,       1,     13,      7,       0,       0,     0,        0,       0,     0,      0,      0},
                             {80,      6,       1,     12,      7,       1,       2,     17,       0,       0,     0,      0,      0},
                             {90,      6,       1,     11,      7,       2,       2,     17,       0,       0,     0,      0,      0},
                             {100,     6,       1,     10,      7,       3,       2,     17,       0,       0,     0,      0,      0},
                             {110,     0,       1,     9,      7,       5,       2,     17,       0,       0,     0,      0,      0},
                             {120,     0,       1,     8,      7,       8,       2,     17,       0,       0,     0,      0,      0},
                             {130,     0,       1,     14,      7,      10,      2,     17,       0,       0,     0,      0,      0},
                             {140,     0,       1,     14,      7,      10,      2,     17,       1,       3,    17,      0,      0},
                             {150,     0,       1,     14,      7,       8,       2,     14,       3,       3,    17,      0,      0},
                             {160,     0,       1,     14,       7,       5,       2,     14,       6,       3,    17,      0,      0},
                             {170,     0,       1,     14,       7,       5,       2,     11,       7,       3,    14,      0,      0},
                             {180,     0,       0,     14,       7,       5,       2,     11,       7,       3,    14,      1,      17},
                             {419,     0,       0,     14,       7,       4,       2,     11,       8,       3,    14,      3,      14},
                             {200,     0,       0,     14,       7,       4,       2,     10,       8,       3,    14,      5,      11} };
                 
#endif
