#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void delay(int delayTime)
{
	long int preTime = time(NULL);
	while(preTime + delayTime > time(NULL)){}
}