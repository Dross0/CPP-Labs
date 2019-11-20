//
// Created by Андрей Гайдамака on 19.11.2019.
//

#ifndef TASK3_GAME_H
#define TASK3_GAME_H
#include "IGamer.h"
#include <map>
#include <string>
#include <memory>

enum class Gamer_type : unsigned int{
    OPTIMAL_GAMER,
    RANDOM_GAMER,
    CONSOLE_GAMER
};

class Game {
public:
    Game(Gamer_type gamer1, Gamer_type gamer2);

    Game(const Game & g) = delete;

    void play() const;
private:
    std::shared_ptr<IGamer> gamer1_;
    std::shared_ptr<IGamer> gamer2_;

    void change_statistics(std::map<std::string, unsigned int> & stats, HIT_STATUS hit_status) const;
};


#endif //TASK3_GAME_H
