#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>
#include "Output.h"
#include "Input.h"

class Player
{
    public:
        void Start();
        void Update();
        void TakeDamage(); //Decrementa il valore della vita (1 punto)
        void ScorePoint( const int &points = 1 ); //Incrementa il punteggio (valore di default: 1)

        static Player& Get();
    private:

        Player();

        void PrintPlayer();
        void PrintLifeBars();
        void EndGame();

        void stepLeft();
        void stepRight();

        COORD m_pos;
        int m_length;
        int m_lives;
        int m_score;
};

#endif // PLAYER_H
