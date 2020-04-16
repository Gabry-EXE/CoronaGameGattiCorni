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

    //the player is on another thread because it waits for input, blocking his thread
    std::thread playerThread(PlayerThread);

    while(inGame)
    {
        Output::Get().Update(); //print the screen
        EnemyManager::Get().Update(); //spawn enemies
    }

    //END GAME
    //called manually because when the game finishes it would stops printing
    Output::Get().Update();

    //wait for player input before printing game stats
    playerThread.join(); //join waits until the thread stops

    //clear the string
    Output::Get().FillChar({ 0, 0 }, { SCREEN_WIDTH, SCREEN_HEIGHT }, ' ', BACKGROUND_PURPLE);

    //pick a random phrase to be displayed
    const std::string losePhrases[] = { "You're a loser", "You lost", "GG", "LOL, you lost", ":(", "You got corona", "Fatal error", "Execution killed" };
    std::string losePhrase = losePhrases[rand() % 8];
    Output::Get().PrintString( SCREEN_HEIGHT / 3, losePhrase, FOREGROUND_YELLOW | BACKGROUND_PURPLE);


    Output::Get().Update();
    //until the player doesn't press ESCAPE, the game doesn't close
    while(!Input::Get().IsPressed(VK_ESCAPE)) {}

    return 0;
}
