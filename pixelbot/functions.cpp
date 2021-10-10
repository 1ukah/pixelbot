#include "includes.h"

bool funcs::left_hold = false;
bool funcs::left_click = false;

void funcs::funcs_thread()
{
	if (funcs::left_hold)
	{
		if (menu::global_key == false)
			return;

		inputs::m_left_input(5000);
	}

	if (funcs::left_click)
	{
		if (funcs::left_click == false)
			return;

		if (pixel_bot::debug == true)
			return;

		if (GetAsyncKeyState(VK_RBUTTON))
			return;

		inputs::m_left_input(0);
		Sleep(69);
	}
}