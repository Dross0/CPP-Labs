//
// Created by Андрей Гайдамака on 21.11.2019.
//

#ifndef TASK3_MYOPTIONPARSER_H
#define TASK3_MYOPTIONPARSER_H
#include "lib/optionparser.h"
#include "GameSettings.h"


enum Option_index{
    UNKNOWN,
    HELP,
    GAMER1,
    GAMER2,
    ROUNDS,
};


Game_config  parse_arguments(int argc, char ** argv);


#endif //TASK3_MYOPTIONPARSER_H
