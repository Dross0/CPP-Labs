//
// Created by Андрей Гайдамака on 25.10.2019.
//

#include "OptimalGamer.h"
#include <algorithm>
#include <random>

HIT_STATUS OptimalGamer::get_hit(uint8_t row, uint8_t col) {
    HIT_STATUS status = personal_.hit(row, col);
    return status;
}

HIT_STATUS OptimalGamer::make_move(std::shared_ptr<IGamer> rival) {
    static uint32_t row = 1;
    static uint32_t col = 'a';
    while (std::find(wrong_points_.begin(), wrong_points_.end(), std::make_pair(row, col)) != wrong_points_.end()){
            col += 1;
            row += col / ('j' + 1);
            col = (col == 'j' + 1) ? 'a' : col;
    }
    HIT_STATUS status = rival->get_hit(row, col);
    if (status == HIT_STATUS::MISS){
        hits_field_(row, col) = 3;
        wrong_points_.emplace_back(row, col);
    }
    else if (status == HIT_STATUS::HIT){
        hits_field_(row, col) = 2;
        wrong_points_.emplace_back(row, col);
    }
    else if (status == HIT_STATUS::KILL){
        hits_field_(row, col) = 2;
        std::vector<std::pair<uint32_t , uint32_t >> points_of_ship;
        points_of_ship.emplace_back(row, col);
        int32_t direction = 0;
        if (row - 1 > 0 && hits_field_(row - 1, col) == 2){
             direction = 1;
        }
        else if (row + 1 <= 10 && hits_field_(row + 1, col) == 2){
            direction = 2;
        }
        else if (col - 1 > 'a' && hits_field_(row, col - 1) == 2){
            direction = 3;
        }
        else if (col + 1 <= 'j' && hits_field_(row, col + 1) == 2){
            direction = 4;
        }
        while (true){
            if (direction == 1 && row - 1 > 0 && hits_field_(row - 1, col) == 2){
                row--;
            }
            else if (direction == 2 && row + 1 <= 10 && hits_field_(row + 1, col) == 2){
                row++;
            }
            else if (direction == 3 && col - 1 > 'a' && hits_field_(row, col - 1) == 2){
                col--;
            }
            else if (direction == 4 && col + 1 <= 'j' && hits_field_(row, col + 1) == 2){
                col++;
            }
            else{
                break;
            }
            points_of_ship.emplace_back(row, col);
        }
        for (auto & i : points_of_ship){
            wrong_points_.push_back(i);
            wrong_points_.emplace_back(i.first, i.second - 1);
            wrong_points_.emplace_back(i.first, i.second + 1);
            wrong_points_.emplace_back(i.first + 1, i.second);
            wrong_points_.emplace_back(i.first + 1, i.second - 1);
            wrong_points_.emplace_back(i.first + 1, i.second + 1);
            wrong_points_.emplace_back(i.first - 1, i.second);
            wrong_points_.emplace_back(i.first - 1, i.second - 1);
            wrong_points_.emplace_back(i.first - 1, i.second + 1);
        }
    }
    return status;
}

void OptimalGamer::place_ships() {
    std::default_random_engine generator;
    generator.seed(time(nullptr));
    std::uniform_int_distribution<int> distribution(0, 1000);
    Direction dirs[] = {Direction::UP, Direction::DOWN, Direction::RIGHT, Direction::LEFT};
    for (uint8_t i = 0; i < 10; ++i){
        try{
            uint8_t row = 1 + distribution(generator) % 10;
            uint8_t col = 'a' + distribution(generator) % 10;
            Direction dir = dirs[distribution(generator) % 4];
            if (i == 0){
                personal_.place(row, col, dir, 4);
            }
            else if (i >= 1 && i <= 2){
                personal_.place(row, col, dir, 3);
            }
            else if (i >= 3 && i <= 5){
                personal_.place(row, col, dir, 2);
            }
            else{
                personal_.place(row, col, dir, 1);
            }
        }
        catch (const std::runtime_error& error){
            i--;
        }
    }
}

bool OptimalGamer::check_lose(){
    return 0 == personal_.get_alive_ships_amount();
}

void OptimalGamer::print_personal_field(){
    personal_.print();
}

void OptimalGamer::print_hits_field(){
    hits_field_.print();
}