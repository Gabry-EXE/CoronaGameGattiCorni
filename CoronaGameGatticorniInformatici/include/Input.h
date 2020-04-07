#ifndef INPUT_H
#define INPUT_H

#include <windows.h>

class Input
{
    public:
        //https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
        bool IsPressed(const DWORD &keyCode);

        static Input& Get();
    private:
        Input();
        HANDLE m_hStdIn; //standard input handle
        DWORD m_readNums; //number of inputs
        INPUT_RECORD m_inputBuffer[128];
        bool m_canPress; //to prevent holding a key
};

#endif // INPUT_H
