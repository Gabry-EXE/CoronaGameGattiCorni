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
        Output::Get().Update(); //print the screen
        Player::Get().Update(); //check input and move player
        EnemyManager::Get().Update(); //spawn enemies
    }

    return 0;
}
