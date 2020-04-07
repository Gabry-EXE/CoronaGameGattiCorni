#include "EnemyManager.h"

EnemyManager::Get()
{
    static EnemyManager m_instance;
    return m_instance;
}

void EnemyManger::Update()
{
    if (m_timer <= 0)
    {
        Spawn();
        m_timer = 1.5;
    }
    else
    {
        m_timer -= DELTA_TIME;
    }

    for (int i = 0; i<enemies.size()   ;i++ )
    {
        enemies[i].Update();
        if (enemies[i].isColliding)
            DeleteEnemy(enemies, i);
    }
}


EnemyManger::EnemyManager()
{
    m_timer = 1.5;
}

void EnemyManager::Spawn()
{

    Enemy new_enemy(rand()%(SCREEN_WIDTH)+1);

    enemies.emplace.push_back(new_enemy);

}


void EnemyManager::DeleteEnemy(const int &INDEX)
{
    enemies.erase(enemies.begin() + INDEX);
}

