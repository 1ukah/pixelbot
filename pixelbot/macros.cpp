#include "includes.h"

bool macros::left_click = false;

void macros::thread()
{
	if (macros::left_click)
	{
		inputs::mouse::click(mouse_flag::left_down, 0, mouse_flag::left_up);
		Sleep(69);
	}
}