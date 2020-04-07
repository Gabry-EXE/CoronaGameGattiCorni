#include "EnemyManager.h"

EnemyManager& EnemyManager::Get()
{
    static EnemyManager m_instance;
    return m_instance;
}

void EnemyManager::Update()
{
    if (m_timer <= 0)
    {
        Spawn();
        m_timer = 2;
    }
    else
    {
        m_timer -= DELTA_TIME;
    }

    for (int i = 0; i<enemies.size()   ;i++ )
    {
        enemies[i].Update();
        if (enemies[i].isColliding)
            DeleteEnemy(i);
    }
}


EnemyManager::EnemyManager()
{
    srand(time(NULL));
    m_timer = 2;
}

void EnemyManager::Spawn()
{

    Enemy new_enemy(rand()%(SCREEN_WIDTH)+1);

    enemies.emplace_back(new_enemy);

}


void EnemyManager::DeleteEnemy(const int &INDEX)
{
    enemies.erase(enemies.begin() + INDEX);
}

