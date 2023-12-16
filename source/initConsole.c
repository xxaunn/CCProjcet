#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void SetConsoleWindowSize(SHORT x, SHORT y);

void initConsole()
{
	SetConsoleTitle("DINO");
	SetConsoleWindowSize(100, 10);
	return 0;
}

void SetConsoleWindowSize(SHORT x, SHORT y)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.dwFontSize.X = x;
	cfi.dwFontSize.Y = y;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}