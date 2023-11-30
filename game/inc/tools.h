/**
 * @file
 * @brief     Tools class
 * @copyright Diego SIERRA
 *  TODO: search how to use and test compiler explorer https://godbolt.org/ 
 */

#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <cstdint>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>

#define LIM_LEFT 3
#define LIM_RIGHT 76
#define RIGHT   77
#define LEFT    75
#define UP      72
#define DOWN    80
#define POINT   5
#define MAX_HEALTH 2
#define MAX_LIFE 2
#define ARROW_DOWN 25
#define ENTER 13
#define ESC 27
#define SPACE 32

enum Collision
{
    NONE    = 0,
    Asteroid_Destroyed,
    Spaceship_impacted,
    Lost_life,
    Game_Over
};

void gotoxy(int x, int y);
void ConsoleColor(int n);
void hideCursor();
char getKey();

#endif
