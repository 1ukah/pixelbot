#pragma once
#include "includes.h"

namespace utils
{
	extern HWND find_wnd_func(LPCWSTR target_name);
	extern RECT get_wnd_rect(HWND target_name);
	extern bool play_beep(bool func);
}