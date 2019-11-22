//
// Created by Андрей Гайдамака on 19.11.2019.
//

#ifndef TASK3_GAME_H
#define TASK3_GAME_H
#include "GameSettings.h"
#include <map>
#include <string>
#include <memory>
#include "IGamer.h"

class IGamer;

enum class Gamer_number : uint32_t{
    FIRST,
    SECOND,
};

class Game {
public:
    explicit Game(Game_config gf);

    Game(const Game & g) = delete;

    HIT_STATUS make_move(uint32_t row, uint32_t col);

    bool check_rival_lose();

    GameField & get_current_gamer_field();

    void play();

    GameField &get_rival_gamer_field();
private:
    Game_config game_config_;
    GameField gamer1_field_;
    GameField gamer2_field_;
    Gamer_number current_gamer_number_;

    void change_statistics(std::map<std::string, unsigned int> & stats, HIT_STATUS hit_status) const;

    std::shared_ptr<IGamer> make_player(Gamer_type gamer_type) const;

};


#endif //TASK3_GAME_H
