#include "includes.h"

bool macros::left_click = false;

void macros::thread()
{
	if (macros::left_click)
	{
		inputs::mouse::left(0);
		Sleep(69);
	}
}