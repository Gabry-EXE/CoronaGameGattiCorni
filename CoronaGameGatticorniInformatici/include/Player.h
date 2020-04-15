#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>
#include "Output.h"
#include "Input.h"
#include <conio.h>

class Player
{
    public:
        void Start();
        void Update();
        //decrease the number of lives by 1
        void TakeDamage();
        //increase the score
        void ScorePoint( const int &points = 1 );

        static Player& Get();
    private:

        Player();

        void PrintPlayer();
        void PrintLifeBars();
        void EndGame();

        void stepLeft();
        void stepRight();

        COORD m_pos;
        int m_length; //lenght of the bar
        int m_lives;
        int m_score;
};

#endif // PLAYER_H
