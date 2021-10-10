#pragma once
#include "includes.h"

namespace inputs
{
	extern void kb_key_input(CHAR key_code, int sleep_time);
	extern void kb_key_hold(CHAR key_code);
	extern void kb_key_release(CHAR key_code);
	extern void kb_enter_input(int sleep_time);

	extern void m_left_input(int sleep_time);
	extern void m_left_hold();
	extern void m_left_release();
}