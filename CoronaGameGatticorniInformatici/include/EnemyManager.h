#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <vector>
#include <Enemy.h>

#include<ctime>
#include<cstdlib>


class EnemyManager
{
    public:
        void Start();
        void Update();
    private:
        srand(time(NULL));

        EnemyManager();

        std::vector<Enemy> enemies;

        void Spawn();
        void DeleteEnemy();

    public:
        static EnemyManager Get();
};

#endif // ENEMYMANAGER_H
