//
// Created by Андрей Гайдамака on 21.11.2019.
//

#ifndef TASK3_GAMESETTINGS_H
#define TASK3_GAMESETTINGS_H

enum class Gamer_type : unsigned int{
    OPTIMAL_GAMER,
    RANDOM_GAMER,
    CONSOLE_GAMER
};

struct Game_config{
    int count;
    Gamer_type gamer1;
    Gamer_type gamer2;
};

#endif //TASK3_GAMESETTINGS_H
