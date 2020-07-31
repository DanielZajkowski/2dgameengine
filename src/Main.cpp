#include <iostream>
#include "Game.h"
#include "Constants.h"

int main(int argc, char *args[])
{
    Game *game = new Game();

    game->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (game->IsRunning())
    {
        game->ProcessInput();
        game->Update();
        game->Render();
    }
    
    game->Destroy();

    return 0;
}