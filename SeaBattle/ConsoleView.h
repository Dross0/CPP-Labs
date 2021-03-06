//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK3_CONSOLEVIEW_H
#define TASK3_CONSOLEVIEW_H

#include "IGameView.h"



class ConsoleView: public IGameView{
public:
    ConsoleView() = default;

    void draw(Game& game, std::map<std::string, unsigned int> &stat, HIT_STATUS hit_status) const override;
private:
    void scroll(unsigned int number_of_lines) const;
    void print_rival_field(const GameField & gf) const;
};


#endif //TASK3_CONSOLEVIEW_H
