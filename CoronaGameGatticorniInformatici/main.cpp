#include <Output.h>
#include <Player.h>
#include <EnemyManager.h>

bool inGame = true;

int main()
{
    Player::Get().Start();
    EnemyManager::Get().Start();

    while(inGame)
    {
        Output::Get().Update();
        Player::Get().Update();
        EnemyManager::Get().Update();
    }

    return 0;
}
