#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <vector>
#include <Enemy.h>
#include <Output.h>

#include<ctime>
#include<cstdlib>


class EnemyManager
{
    public:
        void Update();
        static EnemyManager& Get();
    private:
        EnemyManager();

        std::vector<Enemy> enemies;

        void Spawn();
        void DeleteEnemy(const int &INDEX);
        float m_timer;
};

#endif // ENEMYMANAGER_H
