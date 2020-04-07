#include <Output.h>
#include <Player.h>
#include <EnemyManager.h>

bool inGame = true;

int main()
{
    Player::Get().Start();
    Output::Get().Start();

    while(inGame)
    {
        Player::Get().Update(); //check input and move player
        EnemyManager::Get().Update(); //spawn enemies
        Output::Get().Update(); //print the screen
    }


    return 0;
}
