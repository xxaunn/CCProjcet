#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void screenScroll(char a[10][105], int step)
{
	int i, j;
	char newPoint[10] ="       ** ";

	for (i = 0; i < 10; i++)
	{
		a[i][103] = newPoint[i];
	}
	if (step % 5 == 0)
	{
		a[8][103] = '#';
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 103; j++)
		{
			a[i][j] = a[i][j + 1];
		}
	}
}