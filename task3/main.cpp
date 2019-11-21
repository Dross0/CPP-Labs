#include <iostream>
#include "Game.h"
#include "OptionParser.h"
#include "GameSettings.h"

using namespace std;

int main(int argc, char ** argv) {
    Game_config gf = parse_arguments(argc, argv);
    Game game(gf);
    game.play();
    return 0;
}