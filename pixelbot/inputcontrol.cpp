#include "includes.h"

void inputs::kb_key_input(CHAR key_code, int sleep_time)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = VkKeyScanA(key_code);
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(sleep_time);
    input.ki.wVk = VkKeyScanA(key_code);
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

void inputs::kb_key_hold(CHAR key_code)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = VkKeyScanA(key_code);
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));
}

void inputs::kb_key_release(CHAR key_code)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = VkKeyScanA(key_code);
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

void inputs::kb_enter_input(int sleep_time)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = 0x0D;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(input));
    Sleep(sleep_time);
    input.ki.wVk = 0x0D;
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void inputs::m_left_input(int sleep_time)
{
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));
    Sleep(sleep_time);
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

void inputs::m_left_hold()
{
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));
}

void inputs::m_left_release()
{
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}
