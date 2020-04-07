#include "Input.h"

Input::Input()
{
    m_hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(m_hStdIn, ENABLE_WINDOW_INPUT);
    m_canPress = true;
}

bool Input::IsPressed(const DWORD &keyCode)
{
    ReadConsoleInput(m_hStdIn, //the input handle
                     m_inputBuffer, //where to store read data
                     128, //how many data to read
                     &m_readNums); //actual number of reads

    //check 128 times because there could be other events (like mouse move)
    for(int i = 0; i < 128; i++)
    {
        //if the event is a key press
        if(m_inputBuffer[i].EventType == KEY_EVENT)
        {
//            if(m_canPress)
//            {
                //if you just pressed a key, you can't press it again unless you release it
//                m_canPress = false;
                return m_inputBuffer[i].Event.KeyEvent.wVirtualKeyCode == keyCode;
//            }

            //if no keys are pressed, than you can press one
//            if(!m_inputBuffer[i].Event.KeyEvent.bKeyDown)
//                m_canPress = true;
        }
    }

    return false;
}

Input& Input::Get()
{
    static Input s_instance;
    return s_instance;
}
