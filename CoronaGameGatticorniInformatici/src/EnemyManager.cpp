#include "EnemyManager.h"

//singleton
EnemyManager& EnemyManager::Get()
{
    static EnemyManager m_instance;
    return m_instance;
}

void EnemyManager::Update()
{
    //spawn a new enemy each m_timer seconds
    if (m_timer <= 0)
    {
        Spawn();
        m_timer = 2.5;
    }
    else
    {
        m_timer -= DELTA_TIME;
    }

    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].Update();
        if (enemies[i].isColliding)
            DeleteEnemy(i);
    }
}


EnemyManager::EnemyManager()
{
    srand(time(NULL));
    m_timer = 1; //for the first enemy it waits a bit less
}

void EnemyManager::Spawn()
{
    Enemy new_enemy(rand() % SCREEN_WIDTH + 1);
    enemies.push_back(new_enemy);
}

void EnemyManager::DeleteEnemy(const int &index)
{
    //enemies.begin() is an iterator pointing to the first element
    //by adding + index it returns an iterator pointing to the desired element
    enemies.erase(enemies.begin() + index);
}

