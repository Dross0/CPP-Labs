#include "Game.h"
#include "OptionParser.h"
#include "GameSettings.h"

int main(int argc, char ** argv) {
    Game_config game_config = parse_arguments(argc, argv);
    Game game(game_config);
    game.play();
    return 0;
}