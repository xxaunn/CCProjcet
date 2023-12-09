#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void Clr();
void SetConsoleWindowSize(SHORT x, SHORT y);

int printScreen(char const screenP[10][101], int h)
{
	SetConsoleWindowSize(100, 10);
	Clr();
	int i;

	for (i = 0; i < h; i++)
	{
		printf("%s\n", screenP[i]);
	}
	return 0;
}


void Clr()
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize,coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}

void SetConsoleWindowSize(SHORT x, SHORT y)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.dwFontSize.X = x;
	cfi.dwFontSize.Y = y;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),FALSE, &cfi);
}