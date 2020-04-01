#ifndef ENEMY_H
#define ENEMY_H

#include <windows.h>

class Enemy
{
    public:
        Enemy();

        bool isColliding;

        void Start();
        void Update();
    private:
        COORD m_pos;
        void Move();
};

#endif // ENEMY_H
