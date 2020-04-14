#include <conio.h>
#include <Output.h>
#include <Player.h>
#include <EnemyManager.h>
#include <ctime>
#include <cstdlib>

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
    srand(time(0));
    Output::Get().Start();
    Player::Get().Start();

    std::thread playerThread(PlayerThread);

    while(inGame)
    {
        Output::Get().Update(); //print the screen
        EnemyManager::Get().Update(); //spawn enemies
    }

    //END GAME
    Output::Get().Update();
    //wait for player input before printing game stats
    playerThread.join();

    Output::Get().FillChar({ 0, 0}, { SCREEN_WIDTH, SCREEN_HEIGHT }, ' ', BACKGROUND_PURPLE);

    const std::string losePhrases[] = { "You're a loser", "You lost", "GG", "LOL, you lost", ":(", "You got corona", "Fatal error", "Execution killed" };
    std::string losePhrase = losePhrases[rand() % 8];
    Output::Get().PrintString( SCREEN_HEIGHT / 3, losePhrase, FOREGROUND_YELLOW | BACKGROUND_PURPLE);


    Output::Get().Update();
    while(!Input::Get().IsPressed(VK_ESCAPE)) {}

    return 0;
}
