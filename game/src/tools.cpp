/**
 * @file
 * @brief     Tools class
 * @copyright Diego SIERRA
 */

#include "tools.h"

void Tools::gotoxy(int x, int y)
{
    /*
    This fonction (in windows.h) permit to move the cursor to x,y position
    TODO:to improuve this fonction, see this link https://www.youtube.com/watch?v=OB9rUqe_Cd4&list=RDCMUCSdIAKvPxlB3VlFDCBvI46A&start_radio=1
    */
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void Tools::ConsoleColor(int n)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, n);  
}

void Tools::hideCursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 50;
    cci.bVisible = FALSE;    
    SetConsoleCursorInfo(hCon, &cci);
}

int Tools::getKey() {
    if (_kbhit()) {  return _getch(); }
    else    return ' ';
}
