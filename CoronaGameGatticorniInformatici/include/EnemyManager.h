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
        void Start();
        void Update();
        static EnemyManager& Get();
    private:
        srand(time(NULL));

        EnemyManager();

        std::vector<Enemy> enemies;

        void Spawn();
        void DeleteEnemy(const int &INDEX);
        float m_timer;

    public:
        static EnemyManager Get();

};

#endif // ENEMYMANAGER_H
