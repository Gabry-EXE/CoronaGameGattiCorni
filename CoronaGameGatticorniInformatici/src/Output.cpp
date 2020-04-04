#include "Output.h"


Output::Output()
{
    //set the write destination rectangle
    writeRect.Left = 0;
    writeRect.Right = SCREEN_WIDTH - 1;
    writeRect.Top = 0;
    writeRect.Bottom = SCREEN_HEIGHT - 1;

    //initialize charBuffer
    for(int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
    {
        charBuffer[i].Attributes = FOREGROUND_INTENSITY;
        charBuffer[i].Char.AsciiChar = ' ';
    }

    bufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };

    screenBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(screenBuffer);
}

void Output::PrintChar(const COORD &position, const char &glyph, const WORD &color)
{
    charBuffer[position.Y * SCREEN_WIDTH + position.X].Attributes = color;
    charBuffer[position.Y * SCREEN_WIDTH + position.X].Char.AsciiChar = glyph;
}

char Output::GetChar(const COORD &position)
{
    return charBuffer[position.Y * SCREEN_WIDTH + position.X].Char.AsciiChar;
}

void Output::FillChar(const COORD &pos, const COORD &rectSize, const char &glyph, const WORD &color)
{
    for(int y = pos.Y; y < pos.Y + rectSize.Y; y++)
    {
        for(int x = pos.X; x < pos.X + rectSize.X; x++)
        {
            PrintChar({ x, y }, glyph, color);
        }
    }
}

void Output::Update()
{
    WriteConsoleOutput(screenBuffer, //which buffer to write in
                       charBuffer, //what to write
                       bufferSize, //how much
                       { 0, 0 }, //where
                       &writeRect); //windows need this, I don't
   std::this_thread::sleep_for(std::chrono::seconds((int)(DELTA_TIME * 1000)));
}

Output& Output::Get()
{
    static Output s_instance;
    return s_instance;
}
