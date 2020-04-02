#include "EnemyManager.h"

EnemyManager::Get()
{
    static EnemyManager m_instance;
    return m_instance;
}

void EnemyManger::Update()
{
    for (int i = 0; i<enemies.size()   ;i++ )
        {
            enemies[i].Update();
            if (enemies[i].isColliding)
                DeleteEnemy();
        }
}


EnemyManger::EnemyManager()
{
    Spawn();
    DeleteEnemy();
}

void Spawn()
{

    Enemy new_enemy(rand()%(SCREEN_WIDTH)+1);

    enemies.emplace.push_back(new_enemy);

}


void DeleteEnemy()
{

}

