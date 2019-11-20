#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    Game game(Gamer_type::RANDOM_GAMER, Gamer_type::RANDOM_GAMER);
    game.play();
    return 0;
}