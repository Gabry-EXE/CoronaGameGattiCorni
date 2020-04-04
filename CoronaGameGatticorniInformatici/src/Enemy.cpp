#include "Enemy.h"


Enemy::Enemy(const int &x)
{
    isColliding = false;
    m_timer = 0;
    m_pos.X = x;
    m_pos.Y = 0;
};

//        void Start(const int &x, const int &y)
//        {
//
//        };

void Enemy::Update()
{
    Move();
    if (Output::Get().GetChar(m_pos) != ' ')
    {
        isColliding = true;
    }
    else
    {
        Output::Get().PrintChar(m_pos, '$'/*enemyGlyph*/, FOREGROUND_WHITE);
    }
};



void Enemy::Move()
{
    m_pos.Y++;
};

