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
        HANDLE hStdIn; //standard input handle
        DWORD readNums; //number of inputs
        INPUT_RECORD inputBuffer[128];
        bool canPress; //to prevent holding a key
};

#endif // INPUT_H
