#include "includes.h"

HWND target_wnd = utils::find_wnd_func(target);

int main()
{
	while (target_wnd == NULL)
	{
		cout << "Target window not found!" << endl;
		Sleep(2000);
	}

	menu::update_menu();
	while (true)
	{
		if (GetAsyncKeyState(VK_END))
		{
			Beep(200, 300);
			return 0;
		}

		menu::key_binds();
		funcs::funcs_thread();
		pixel_bot::run();
	}
}