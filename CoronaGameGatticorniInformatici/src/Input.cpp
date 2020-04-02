#include "Input.h"

Input::Input()
{
    hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hStdIn, ENABLE_WINDOW_INPUT);
    canPress = true;
}

bool Input::IsPressed(const DWORD &keyCode)
{
    ReadConsoleInput(hStdIn, //the input handle
                     inputBuffer, //where to store read data
                     128, //how many data to read
                     &readNums); //actual number of reads

    //check 128 times because there could be other events (like mouse move)
    for(int i = 0; i < 128; i++)
    {
        //if the event is a key press
        if(inputBuffer[0].EventType == KEY_EVENT)
        {
            DWORD inputChar = inputBuffer[0].Event.KeyEvent.wVirtualKeyCode;

            //if no keys are pressed, than you can press one
            if(inputBuffer[0].Event.KeyEvent.bKeyDown)
                canPress = true;

            if(canPress)
            {
                //if you just pressed a key, you can't press it again unless you release it
                canPress = false;
                return inputChar == keyCode;
            }
        }
    }

    return false;
}

Input& Input::Get()
{
    static Input s_instance;
    return s_instance;
}
