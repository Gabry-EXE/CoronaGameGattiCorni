#ifndef ENEMY_H
#define ENEMY_H

#include "Output.h"


class Enemy
{
    public:
        Enemy(const int &x);

        bool isColliding;

//        void Start(const int &x, const int &y);
        void Update();

    private:
        float m_timer;
        COORD m_pos;
        void Move();
};

#endif // ENEMY_H
