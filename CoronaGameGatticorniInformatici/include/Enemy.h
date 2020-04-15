#ifndef ENEMY_H
#define ENEMY_H

#include "Output.h"
#include "Player.h"

class Enemy
{
    public:
        Enemy(const int &x);

        //public variable for the EnemyManager
        bool isColliding;
        void Update();

    private:
        float m_timer; //secs btw each move
        COORD m_pos; //current position
        void Move();
};

#endif // ENEMY_H
