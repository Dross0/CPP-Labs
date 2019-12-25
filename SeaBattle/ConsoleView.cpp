//
// Created by Андрей Гайдамака on 25.10.2019.
//

#include "ConsoleView.h"
#include <iostream>


void ConsoleView::draw(Game & game, std::map<std::string, unsigned int> &stat,
                       HIT_STATUS hit_status) const {
    switch (hit_status) {
        case HIT_STATUS::MISS:
            std::cout << "Промах" << std::endl;
            break;
        case HIT_STATUS::HIT:
            std::cout << "Попадание" << std::endl;
            break;
        case HIT_STATUS::KILL:
            std::cout << "Убийство" << std::endl;
            break;
    }
    std::cout << "Your field:" << std::endl;
    game.get_current_gamer_field().print();
    std::cout << "Your hits field:" << std::endl;
    print_rival_field(game.get_rival_gamer_field());
    unsigned int total = stat["total_number"];
    std::cout << "Statistics: " << std::endl;
    std::cout << " Total - " << total << std::endl;
    std::cout << " Number of misses - " << stat["miss_count"] << std::endl;
    std::cout << " Percent of misses - " << static_cast<double>(stat["miss_count"]) / total * 100 << "%" << std::endl;
    std::cout << " Number of hits - " << stat["hit_count"] << std::endl;
    std::cout << " Percent of hits - " << static_cast<double>(stat["hit_count"]) / total * 100 << "%" << std::endl;
    std::cout << " Number of kills - " << stat["kill_count"] << std::endl;
    scroll(15);
}

void ConsoleView::scroll(unsigned int number_of_lines) const {
    for (unsigned int i = 0; i < number_of_lines; ++i) {
        std::cout << std::endl;
    }
}

void ConsoleView::print_rival_field(const GameField &gf) const {
    for (int row = 0; row < 10; ++row){
        for (int col = 0; col < 10; ++col){
            char symbol = '.';
            if (gf(row + 1, col + 'a') == Cell_status::DAMAGED_SHIP){
                symbol = 'X';
            }
            else if (gf(row + 1, col + 'a') == Cell_status::MISS){
                symbol = 'o';
            }
            std::cout << symbol << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}