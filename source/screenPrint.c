
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void screenPrint(char const screenP[10][105])
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Clear the console
	FillConsoleOutputCharacter(hConsole, TEXT(' '), 105 * 10, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);

	// Write the new content
	WriteConsole(hConsole, screenP, 1050, &cCharsWritten, NULL);
}*/

#include <Windows.h> // Make sure to include the necessary header file for Windows API

void Clr();

void screenPrint(const char screenP[10][105]) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { 105, 10 };
	COORD bufferCoord = { 0, 0 };
	SMALL_RECT writeRegion = { 0, 0, 104, 9 };  // Adjust this based on your buffer size

	CHAR_INFO buffer[10][105];

	// Populate the buffer with character and attribute data
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 105; ++j)
		{
			buffer[i][j].Char.AsciiChar = screenP[i][j];
			buffer[i][j].Attributes = FOREGROUND_GREEN;
		}
	}

	// Write the buffer to the console
	WriteConsoleOutput(hConsole, (CHAR_INFO*)buffer, bufferSize, bufferCoord, &writeRegion);
}

void Clr() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Clear the console screen by filling it with spaces
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

	// Move the cursor to the top-left corner of the console
	SetConsoleCursorPosition(hConsole, coordScreen);
}


