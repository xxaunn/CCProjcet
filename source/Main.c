#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "../include/CCProject.h"

#define SCREENWIDTH 100
#define SCREENHEIGHT 10

int main(void)
{
	int i, j, k;
	int tempTime, tempData;
	char screenPoint[SCREENHEIGHT][SCREENWIDTH + 5] =
	{
		{"                                                                                                        \0"},
		{"                                                                                                        \0"},
		{"                                                                                                        \0"},
		{"                                                                                                        \0"},
		{"                                                                                                        \0"},
		{"*          ***    ******    ****    ****        ****            ****         ***                **    **\0"},
		{"*          ***    ******    ****    ****        ****            ****         ***                **    **\0"},
		{"*          ***    ******    ****    ****        ****            ****         ***                **    **\0"},
		{"********************************************************************************************************\0"},
		{"                                                                                                        \0"}
	};

	initConsole();
	
	while (1)
	{
		tempTime
		while()
	}

	printScreen(screenPoint, SCREENHEIGHT);


	system("PAUSE");
	return 0;
}