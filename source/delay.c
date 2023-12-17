#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void delay(int delayTime)
{
	unsigned long preTime = GetTickCount();
	while(preTime + delayTime > GetTickCount()){}
}