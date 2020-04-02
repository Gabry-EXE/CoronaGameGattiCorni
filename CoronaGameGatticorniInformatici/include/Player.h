#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>

class Player
{
    public:

        void Update();

        void TakeDamage(); //Decrementa il valore della vita (1 punto)
        void ScorePoint( int points = 1 ); //Incrementa il punteggio (valore di default: 1)

        static Player& Get();

    private:

        Player();

        void Move();
        void EndGame();

        void stepLeft();
        void stepRight();

        COORD m_pos;
        int m_length;
        int m_lives;
        int m_score;
};

#endif // PLAYER_H
