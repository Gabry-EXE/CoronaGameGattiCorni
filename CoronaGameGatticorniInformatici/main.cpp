#include <Output.h>
#include <Player.h>
#include <EnemyManager.h>

bool inGame = true;

void PlayerThread()
{
    while(inGame)
    {
        Player::Get().Update();
        std::this_thread::sleep_for(std::chrono::microseconds(1));
    }
}

int main()
{
    Output::Get().Start();
    Player::Get().Start();

    std::thread playerThread(PlayerThread);

    while(inGame)
    {
        Output::Get().Update(); //print the screen
        EnemyManager::Get().Update(); //spawn enemies
    }

    playerThread.join();

    return 0;
}
