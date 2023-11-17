/**
 * @file
 * @brief     Tools class
 * @copyright Diego SIERRA
 */

#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
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

#endif
