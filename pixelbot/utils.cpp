#include "utils.h"

HWND utils::find_wnd_func(LPCWSTR target_name)
{
	HWND target_wnd = FindWindow(NULL, target_name);
	return target_wnd;
}

RECT utils::get_wnd_rect(HWND target_name)
{
	RECT rect = {};
	GetWindowRect(target_name, &rect);
	SetForegroundWindow(target_name);
	SetActiveWindow(target_name);
	SetFocus(target_name);
	return rect;
}

bool utils::play_beep(bool func)
{
	auto beep_switch = func ? Beep(650, 300) : Beep(400, 300);
	return beep_switch;
}