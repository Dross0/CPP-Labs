//
// Created by Андрей Гайдамака on 25.10.2019.
//

#include "RandomGamer.h"
#include <random>
#include <algorithm>


std::pair<uint32_t, uint32_t> RandomGamer::get_coordinates(Game &game) const {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0, 1000);
    uint32_t row, col;
    do {
        row = 1 + distribution(generator) % 10;
        col = 'a' + distribution(generator) % 10;
    } while (std::find(wrong_points_.begin(), wrong_points_.end(), std::make_pair(row, col)) != wrong_points_.end());
    return {row, col};
}

void RandomGamer::place_ships(Game & game) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(0, 1000);
    Direction dirs[] = {Direction::UP, Direction::DOWN, Direction::RIGHT, Direction::LEFT};
    for (uint8_t i = 0; i < 10; ++i){
        try{
            uint8_t row = 1 + distribution(generator) % 10;
            uint8_t col = 'a' + distribution(generator) % 10;
            Direction dir = dirs[distribution(generator) % 4];
            if (i == 0){
                game.get_current_gamer_field().place(row, col, dir, 4);
            }
            else if (i >= 1 && i <= 2){
                game.get_current_gamer_field().place(row, col, dir, 3);
            }
            else if (i >= 3 && i <= 5){
                game.get_current_gamer_field().place(row, col, dir, 2);
            }
            else{
                game.get_current_gamer_field().place(row, col, dir, 1);
            }
        }
        catch (const std::runtime_error& error){
            i--;
        }
    }
}

void RandomGamer::add_point_to_wrong_points(uint32_t row, uint32_t col, HIT_STATUS hit_status, Game& game){
    wrong_points_.emplace_back(row, col);
}

