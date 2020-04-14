#include "Output.h"

Output::Output(){}

void Output::Start()
{
    //set the write destination rectangle
    m_writeRect.Left = 0;
    m_writeRect.Right = SCREEN_WIDTH - 1;
    m_writeRect.Top = 0;
    m_writeRect.Bottom = SCREEN_HEIGHT - 1;

    //initialize charBuffer
    for(int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
    {
        m_charBuffer[i].Attributes = BACKGROUND_BLUE;
        m_charBuffer[i].Char.AsciiChar = ' ';
    }

    m_bufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };

    m_screenBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(m_screenBuffer);

    //PRINT GAME TITLE
    PrintString(2, "CORONA_GAME.exe ", BACKGROUND_BLUE | FOREGROUND_YELLOW);
}

void Output::PrintChar(const COORD &position, const char &glyph, const WORD &color)
{
    m_charBuffer[position.Y * SCREEN_WIDTH + position.X].Attributes = color;
    m_charBuffer[position.Y * SCREEN_WIDTH + position.X].Char.AsciiChar = glyph;
}

void Output::PrintString(const COORD &position, const std::string &string, const WORD &color)
{
    for(int i = 0; i < string.size(); i++)
    {
        if(i < SCREEN_WIDTH - 1)
        {
            PrintChar({ position.X + i, position.Y }, string[i], color);
        }
    }
}
void Output::PrintString(const int &yPos, const std::string &string, const WORD &color)
{
    for(int i = 0; i < string.size(); i++)
    {
        if(i < SCREEN_WIDTH - 1)
        {
            PrintChar({ SCREEN_WIDTH / 2 - string.size() / 2 + i, yPos }, string[i], color);
        }
    }
}
char Output::GetChar(const COORD &position)
{
    return m_charBuffer[position.Y * SCREEN_WIDTH + position.X].Char.AsciiChar;
}

void Output::FillChar(const COORD &pos, const COORD &rectSize, const char &glyph, const WORD &color)
{
    for(int y = pos.Y; y < (pos.Y + rectSize.Y); y++)
    {
        for(int x = pos.X; x < (pos.X + rectSize.X); x++)
        {
            PrintChar({ x, y }, glyph, color);
        }
    }
}

void Output::Update()
{
    WriteConsoleOutput(m_screenBuffer, //which buffer to write in
                       m_charBuffer, //what to write
                       m_bufferSize, //how much
                       { 0, 0 }, //where
                       &m_writeRect); //Windows needs this, I don't
   std::this_thread::sleep_for(std::chrono::milliseconds((int)(DELTA_TIME * 1000))); //when to write
}

Output& Output::Get()
{
    static Output s_instance;
    return s_instance;
}
