#pragma once

namespace inputs
{
    namespace keyboard
    {
        inline void key(CHAR key_code, int sleep_time)
        {
            INPUT input;
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = VkKeyScanA(key_code);
            SendInput(1, &input, sizeof(INPUT));
            Sleep(sleep_time);
            input.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &input, sizeof(INPUT));
        }

        inline void key_hold(CHAR key_code)
        {
            INPUT input;
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = VkKeyScanA(key_code);
            SendInput(1, &input, sizeof(INPUT));
        }

        inline void key_release(CHAR key_code)
        {
            INPUT input;
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = VkKeyScanA(key_code);
            input.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &input, sizeof(INPUT));
        }

        inline void enter(int sleep_time)
        {
            INPUT input;
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = 0x0D;
            SendInput(1, &input, sizeof(input));
            Sleep(sleep_time);
            input.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &input, sizeof(input));
        }
    }
    
    namespace mouse
    {
        inline void left(int sleep_time)
        {
            INPUT input;
            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1, &input, sizeof(INPUT));
            Sleep(sleep_time);
            input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &input, sizeof(INPUT));
        }

        inline void left_hold()
        {
            INPUT input;
            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1, &input, sizeof(INPUT));
        }

        inline void left_release()
        {
            INPUT input;
            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &input, sizeof(INPUT));
        }
    } 
}