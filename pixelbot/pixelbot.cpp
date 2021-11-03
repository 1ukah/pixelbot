#include "includes.h"

HWND pixelbot::target_window = FindWindow(NULL, "");
bool pixelbot::debug = false;
bool pixelbot::example = false;

void pixelbot::run()
{
	if (pixelbot::debug)
	{
		if (GetAsyncKeyState(VK_MULTIPLY))
		{
			SetConsoleTextAttribute(menu::console_handle, 11); // 11 = cyan
			cout << "[ debug ] active window title: " << utils::get_active_wnd_title().c_str() << endl;
			Sleep(1000);
		}

		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			POINT p;
			GetCursorPos(&p);
			ScreenToClient(target_window, &p);

			SetConsoleTextAttribute(menu::console_handle, 11); 
			cout << "[ debug ] x: " << p.x << " | y: " << p.y << endl;
			Sleep(1000);
		}

		if (GetAsyncKeyState(VK_NUMPAD2))
		{
			HDC hDC = GetDC(target_window);
			POINT p;
			GetCursorPos(&p);
			ScreenToClient(target_window, &p);
			COLORREF Color = GetPixel(hDC, p.x, p.y);
			ReleaseDC(target_window, hDC);

			SetConsoleTextAttribute(menu::console_handle, 11); 
			cout << "[ debug ] color: " << Color << " | rgb: ( " << (int)GetRValue(Color) << ", " << (int)GetGValue(Color) << ", " << (int)GetBValue(Color) << " )" << endl;
			Sleep(1000);
		}
	}

	if (pixelbot::example)
	{
		if (menu::global_key == false || pixelbot::debug == true)
			return;

		bool all_good = false; 
		bool all_good2 = false;

		HDC hdc = GetDC(target_window);
		COLORREF pixel = GetPixel(hdc, 1518, 240);
		COLORREF pixel2 = GetPixel(hdc, 812, 362);
		ReleaseDC(target_window, hdc);

		COLORREF pixel_color = 6806002;
		COLORREF pixel2_color = 1819262;

		if (pixel == pixel_color) 
			all_good = true;

		if (pixel2 == pixel2_color)
			all_good2 = true;

		if (all_good == true)
		{
			int quest_x = 1559; int quest_y = 238;

			RECT wrect = utils::get_wnd_rect(target_window);
			SetCursorPos(wrect.left + quest_x, wrect.top + quest_y);

			Sleep(50);
			inputs::mouse::click(mouse_flag::left_down, 0, mouse_flag::left_up);
			Sleep(2000);
		}

		if (all_good2 == true)
		{
			inputs::keyboard::key('t', keyboard_flag::key_down, 0, keyboard_flag::key_up);
			inputs::keyboard::key('e', keyboard_flag::key_down, 0, keyboard_flag::key_up);
			inputs::keyboard::key('s', keyboard_flag::key_down, 0, keyboard_flag::key_up);
			inputs::keyboard::key('t', keyboard_flag::key_down, 0, keyboard_flag::key_up);
			inputs::keyboard::sm_key(sm_keys::enter, keyboard_flag::key_down, 0, keyboard_flag::key_up);
			Sleep(400);
		}
	}
}