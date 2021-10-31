#include "includes.h"

HANDLE menu::console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
bool menu::global_key = false;

void menu::draw()
{
	system("CLS");

	SetConsoleTextAttribute(menu::console_handle, 112); // 112 = black with grey bg
	cout << " [ end ] panic key " << endl << endl;
	SetConsoleTextAttribute(menu::console_handle, NULL);

	if (menu::global_key)
	{
		SetConsoleTextAttribute(menu::console_handle, 10); // 10 = green
		cout << "[ f4 ] global key: on" << endl;
	}
	else
	{
		SetConsoleTextAttribute(menu::console_handle, 12); // 12 = red
		cout << "[ f4 ] global key: off" << endl;
	}

	if (macros::left_click)
	{
		SetConsoleTextAttribute(menu::console_handle, 10);
		cout << "[ numpad5 ] spam left click: on" << endl;
	}
	else
	{
		SetConsoleTextAttribute(menu::console_handle, 12);
		cout << "[ numpad5 ] spam left click: off" << endl;
	}

	if (pixelbot::debug)
	{
		SetConsoleTextAttribute(menu::console_handle, 10);
		cout << "[ numpad0 ] pixel bot debug: on" << endl;
	}
	else
	{
		SetConsoleTextAttribute(menu::console_handle, 12);
		cout << "[ numpad0 ] pixel bot debug: off" << endl;
	}
}

void menu::keybinds()
{
	if (GetAsyncKeyState(VK_F4) & 1)
	{
		menu::global_key = !menu::global_key;
		utils::play_beep(menu::global_key);
		menu::draw();
	}
	else if (GetAsyncKeyState(VK_NUMPAD5) & 1)
	{
		if (menu::global_key == false || pixelbot::debug == true)
			return;

		macros::left_click = !macros::left_click;
		utils::play_beep(macros::left_click);
		menu::draw();
	}
	else if (GetAsyncKeyState(VK_NUMPAD0) & 1)
	{
		if (menu::global_key == false)
			return;

		pixelbot::debug = !pixelbot::debug;
		utils::play_beep(pixelbot::debug);
		menu::draw();
	}
}