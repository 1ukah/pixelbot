#include "includes.h"

int main()
{
	menu::draw();
	while (true)
	{
		if (GetAsyncKeyState(VK_END))
		{
			Beep(200, 300);
			return 0;
		}

		menu::keybinds();
		macros::thread();
		pixelbot::run();
	}
}