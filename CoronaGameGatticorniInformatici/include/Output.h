#ifndef OUTPUT_H
#define OUTPUT_H

#define SCREEN_WIDTH 60
#define SCREEN_HEIGHT 30

#define DELTA_TIME 0.0417

//handy defines for colors
#define FOREGROUND_WHITE FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define BACKGROUND_WHITE BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY
#define FOREGROUND_PURPLE FOREGROUND_BLUE | FOREGROUND_RED
#define BACKGROUND_PURPLE BACKGROUND_BLUE | BACKGROUND_RED
#define FOREGROUND_LIGHT_BLUE FOREGROUND_BLUE | FOREGROUND_GREEN
#define BACKGROUND_LIGHT_BLUE BACKGROUND_BLUE | BACKGROUND_GREEN
#define FOREGROUND_POOP FOREGROUND_GREEN | FOREGROUND_RED
#define BACKGROUND_POOP BACKGROUND_GREEN | BACKGROUND_RED
#define FOREGROUND_YELLOW FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define BACKGROUND_YELLOW BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY

#include <windows.h>
#include <chrono>
#include <thread>

class Output
{
    public:
        void PrintChar(const COORD &position, const char &glyph, const WORD &color);
        char GetChar(const COORD &position);
        void FillChar(const COORD &pos, const COORD &rectSize, const char &glyph, const WORD &color);
        void Update();
        static Output& Get();
    private:
        Output();

        HANDLE m_screenBuffer;
        COORD m_bufferSize;
        SMALL_RECT m_writeRect; //where to write data
        CHAR_INFO m_charBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];
};

#endif // OUTPUT_H
