#include "Enemy.h"


Enemy::Enemy(const int &x)
{
    m_timer = 0.2;
    isColliding = false;
    m_pos.X = x;
    m_pos.Y = 0;
};

void Enemy::Update()
{
    //update enemy position
    if(m_timer <= 0)
    {
        Move();
        m_timer = 0.2;
    }
    else
    {
        m_timer -= DELTA_TIME;
    }
};

void Enemy::Move()
{
    //delete enemy char in the current position, update enemy position
    Output::Get().PrintChar(m_pos, ' ', FOREGROUND_WHITE);
    m_pos.Y++;

    //verify char in the new position; if space it became enemy char, if not space it's colliding with player/bottom of matrix
    if (Output::Get().GetChar(m_pos) != ' ')
    {
        if(Output::Get().GetChar(m_pos) == '=')
        {
            Player::Get().ScorePoint();
        }
        else
        {
            Player::Get().TakeDamage();
        }
        isColliding = true;
    }
    else
    {
        Output::Get().PrintChar(m_pos, '@', FOREGROUND_WHITE);
    }
};
