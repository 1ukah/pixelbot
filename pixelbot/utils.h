#pragma once

namespace utils
{
	inline RECT get_wnd_rect(HWND target_name)
	{
		RECT rect = {};
		GetWindowRect(target_name, &rect);
		SetForegroundWindow(target_name);
		SetActiveWindow(target_name);
		SetFocus(target_name);
		return rect;
	}

	inline std::string get_active_wnd_title()
	{
		HWND hwnd = GetForegroundWindow();
		char wnd_title[256];
		GetWindowText(hwnd, wnd_title, sizeof(wnd_title));
		return wnd_title;
	}

	inline bool play_beep(bool func)
	{
		auto beep_switch = func ? Beep(650, 300) : Beep(400, 300);
		return beep_switch;
	}
}