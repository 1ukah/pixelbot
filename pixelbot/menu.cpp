#include "Menu.h"

HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
bool menu::global_key = false;

void menu::update_menu()
{
	system("CLS");

	if (menu::global_key)
	{
		SetConsoleTextAttribute(console_handle, 10);
		cout << "[ F4 ] -> Global key: ON" << endl << endl;
	}
	else
	{
		SetConsoleTextAttribute(console_handle, 12);
		cout << "[ F4 ] -> Global key: OFF" << endl << endl;
	}

	if (funcs::left_hold)
	{
		SetConsoleTextAttribute(console_handle, 10);
		cout << "[ CAPSLOCK ] -> Hold left click (5s delay): ON" << endl;
	}
	else
	{
		SetConsoleTextAttribute(console_handle, 12);
		cout << "[ CAPSLOCK ] -> Hold left click (5s delay): OFF" << endl;
	}

	if (funcs::left_click)
	{
		SetConsoleTextAttribute(console_handle, 10);
		cout << "[ MULTIPLY ] -> Spam left click (13~ cps): ON" << endl;
	}
	else
	{
		SetConsoleTextAttribute(console_handle, 12);
		cout << "[ MULTIPLY ] -> Spam left click (13~ cps): OFF" << endl;
	}

	if (pixel_bot::buy_bot_func)
	{
		SetConsoleTextAttribute(console_handle, 10);
		cout << "[ MINUS ] -> Spawners buy bot: ON" << endl;
	}
	else
	{
		SetConsoleTextAttribute(console_handle, 12);
		cout << "[ MINUS ] -> Spawners buy bot: OFF" << endl;
	}

	if (pixel_bot::debug)
	{
		SetConsoleTextAttribute(console_handle, 10);
		cout << "[ NUMPAD0 ] -> Pixel bot debug: ON" << endl;
	}
	else
	{
		SetConsoleTextAttribute(console_handle, 12);
		cout << "[ NUMPAD0 ] -> Pixel bot debug: OFF" << endl;
	}
}

void menu::key_binds()
{
	if (GetAsyncKeyState(VK_F4) & 1)
	{
		menu::global_key = !menu::global_key;
		utils::play_beep(menu::global_key);
		menu::update_menu();
	}
	else if (GetAsyncKeyState(VK_CAPITAL) & 1)
	{
		if (menu::global_key == false)
			return;

		funcs::left_hold = !funcs::left_hold;
		utils::play_beep(funcs::left_hold);
		menu::update_menu();
	}
	else if (GetAsyncKeyState(VK_MULTIPLY) & 1)
	{
		if (menu::global_key == false)
			return;

		if (pixel_bot::debug == true)
			return;

		funcs::left_click = !funcs::left_click;
		utils::play_beep(funcs::left_click);
		menu::update_menu();
	}
	else if (GetAsyncKeyState(VK_SUBTRACT) & 1)
	{
		if (menu::global_key == false)
			return;

		if (pixel_bot::debug == true)
			return;

		pixel_bot::buy_bot_func= !pixel_bot::buy_bot_func;
		utils ::play_beep(pixel_bot::buy_bot_func);
		menu::update_menu();
	}
	else if (GetAsyncKeyState(VK_NUMPAD0) & 1)
	{
		if (menu::global_key == false)
			return;

		pixel_bot::debug = !pixel_bot::debug;
		utils::play_beep(pixel_bot::debug);
		menu::update_menu();
	}
}