//
// Created by Андрей Гайдамака on 19.11.2019.
//

#ifndef TASK3_GAME_H
#define TASK3_GAME_H
#include "IGamer.h"
#include "GameSettings.h"
#include <map>
#include <string>
#include <memory>


class Game {
public:
    explicit Game(Game_config gf);

    Game(const Game & g) = delete;

    void play() const;
private:
    Game_config game_config_;

    void change_statistics(std::map<std::string, unsigned int> & stats, HIT_STATUS hit_status) const;

    std::shared_ptr<IGamer> make_player(Gamer_type gamer_type) const;
};


#endif //TASK3_GAME_H
