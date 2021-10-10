#include "includes.h"

bool pixel_bot::debug = false;
bool pixel_bot::buy_bot_func = false;

HWND target_wnd = utils::find_wnd_func(target);

void pixel_bot::run()
{
	if (pixel_bot::debug)
	{
		if (menu::global_key == false)
			return;

		if (GetAsyncKeyState(VK_MULTIPLY))
		{
			POINT p;
			GetCursorPos(&p);
			ScreenToClient(target_wnd, &p);
			cout << "(X) Position: " << p.x << " | (Y) Position: " << p.y << endl;
			Sleep(1000);
		}

		if (GetAsyncKeyState(VK_SUBTRACT))
		{
			HDC hDC = GetDC(target_wnd);
			POINT p;
			GetCursorPos(&p);
			ScreenToClient(target_wnd, &p);
			COLORREF Color = GetPixel(hDC, p.x, p.y);
			ReleaseDC(target_wnd, hDC);
			cout << "Color: " << Color << endl;
			cout << "Red: " << (int)GetRValue(Color) << " | Green: " << (int)GetGValue(Color) << " | Blue: " << (int)GetBValue(Color) << endl;
			Sleep(1000);
		}
	}

	if (pixel_bot::buy_bot_func)
	{
		if (menu::global_key == false)
			return;

		if (pixel_bot::debug == true)
			return;

		bool inv_open = false; bool inv_close = false;
		COLORREF inv_color = 1644825; COLORREF inv_close_color = 2162560;

		HDC hdc = GetDC(target_wnd);
		COLORREF inv_pixel = GetPixel(hdc, 955, 543);
		COLORREF inv_close_pixel = GetPixel(hdc, 946, 928);
		ReleaseDC(target_wnd, hdc);

		if (inv_pixel == inv_color) inv_open = true;
		if (inv_close_pixel == inv_close_color) inv_close = true;

		if (inv_open == true)
		{
			int aslot_x = 1010; int aslot_y = 370;	// Aranha
			int oslot_x = 960; int oslot_y = 370;		// Ovelha
			int eslot_x = 1070; int eslot_y  = 370;	// Esqueleto
			int pslot_x = 802; int pslot_y = 370;
			RECT wrect = utils::get_wnd_rect(target_wnd);
			SetCursorPos(wrect.left + pslot_x, wrect.top + pslot_y);
			Sleep(50);
			inputs::m_left_input(0);
			Sleep(400);
		}
		else if (inv_close == true)
		{
			int s = 50;
			inputs::kb_key_input('t', 150);
			inputs::kb_key_input('2', s);
			inputs::kb_key_input('9', s);
			inputs::kb_key_input('0', s);
			inputs::kb_key_input('0', s);
			inputs::kb_key_input('0', s);
			inputs::kb_enter_input(150);
			inputs::kb_key_input('q', 150);
			inputs::kb_key_input('t', 150);
			inputs::kb_key_input('/', s);
			inputs::kb_key_input('s', s);
			inputs::kb_key_input('p', s);
			inputs::kb_key_input('a', s);
			inputs::kb_key_input('w', s);
			inputs::kb_key_input('n', s);
			inputs::kb_key_input('e', s);
			inputs::kb_key_input('r', s);
			inputs::kb_enter_input(150);
			Sleep(400);
		}
	}
}