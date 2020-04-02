#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <vector>
#include <Enemy.h>


class EnemyManager
{
    public:
        void Start();
        void Update();
    private:
        EnemyManager();

        std::vector<Enemy> enemies;

        void Spawn();
        void DeleteEnemy();
};

#endif // ENEMYMANAGER_H
