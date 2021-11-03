#pragma once

enum class mouse_flag : DWORD
{
    left_up = MOUSEEVENTF_LEFTUP,
    left_down = MOUSEEVENTF_LEFTDOWN,
    right_up = MOUSEEVENTF_RIGHTUP,
    right_down = MOUSEEVENTF_RIGHTDOWN
};

enum class keyboard_flag : DWORD
{
    key_up = KEYEVENTF_KEYUP,
    key_down = 0
};

//System and Modifier keys
enum class sm_keys : int
{
    backspace = 0x08,
    tab = 0x09,
    enter = 0x0D,
    left_shift = 0xA0,
    right_shift = 0xA1,
    left_ctrl = 0xA2,
    right_ctrl = 0xA3,
    alt = 0x12,
    caps_lock = 0x14,
    esc = 0x1B,
    space = 0x20,
    page_up = 0x21,
    page_down = 0x22,
    end = 0x23,
    home = 0x24,
    left_arrow = 0x25,
    up_arrow = 0x26,
    right_arrow = 0x27,
    down_arrow = 0x28,
    print_screen = 0x2C,
    insert = 0x2D,
    del = 0x2E,
    f1 = 0x70,
    f2 = 0x71,
    f3 = 0x72,
    f4 = 0x73,
    f5 = 0x74,
    f6 = 0x75,
    f7 = 0x76,
    f8 = 0x77,
    f9 = 0x78,
    f10 = 0x79,
    f11 = 0x7A,
    f12 = 0x7B
};

namespace inputs
{
    namespace keyboard
    {
        inline void key(CHAR key_code, keyboard_flag kb_flag, int sleep_time, keyboard_flag kb_flag2)
        {
            INPUT input;
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = VkKeyScanA(key_code);
            ZeroMemory(&input, sizeof(INPUT));

            input.ki.dwFlags = (DWORD)kb_flag;
            SendInput(1, &input, sizeof(INPUT));

            Sleep(sleep_time);

            input.ki.dwFlags = (DWORD)kb_flag2;
            SendInput(1, &input, sizeof(INPUT));
        }

        inline void sm_key(sm_keys sm_key, keyboard_flag kb_flag, int sleep_time, keyboard_flag kb_flag2)
        {
            INPUT input;
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = (int)sm_key;
            ZeroMemory(&input, sizeof(INPUT));

            input.ki.dwFlags = (DWORD)kb_flag;
            SendInput(1, &input, sizeof(INPUT));
            
            Sleep(sleep_time);

            input.ki.dwFlags = (DWORD)kb_flag2;
            SendInput(1, &input, sizeof(INPUT));
        }
    }
    
    namespace mouse
    {
        inline void click(mouse_flag m_flag1, int sleep_time, mouse_flag m_flag2)
        {
            INPUT input;
            input.type = INPUT_MOUSE;
            ZeroMemory(&input, sizeof(INPUT));

            input.mi.dwFlags = (DWORD)m_flag1;
            SendInput(1, &input, sizeof(INPUT));

            Sleep(sleep_time);

            input.mi.dwFlags = (DWORD)m_flag2;
            SendInput(1, &input, sizeof(INPUT));
        }
    }
}