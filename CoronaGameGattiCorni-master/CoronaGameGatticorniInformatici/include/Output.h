#ifndef OUTPUT_H
#define OUTPUT_H


class Output
{
    public:
        void PrintChar(COORD position, char glyph); //COLOR
        void GetChar(COORD position);
        void FillChar(COORD pos1, COORD pos2, char glyph); //COLOR

    private:
        Output();
};

#endif // OUTPUT_H
