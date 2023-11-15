/**
 * @file
 * @brief     Tools class
 * @copyright Diego SIERRA
 */

#include "tools.h"

void gotoxy(int x, int y)
{
    /*
    This fonction (in windows.h) permit to move the cursor to x,y position
    */
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void ConsoleColor(int n)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, n);  
}

void hideCursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 50;
    cci.bVisible = FALSE;    
    SetConsoleCursorInfo(hCon, &cci);
}
