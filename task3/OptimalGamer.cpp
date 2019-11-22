//
// Created by Андрей Гайдамака on 25.10.2019.
//

#include "OptimalGamer.h"
#include "Exceptions/PlacementError.h"
#include <algorithm>
#include <random>



std::pair<uint32_t, uint32_t> OptimalGamer::get_coordinates(Game &game) const {
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

void OptimalGamer::place_ships(Game & game) {
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
        catch (const PlacementError& error){
            i--;
        }
    }
}

void OptimalGamer::add_point_to_wrong_points(uint32_t row, uint32_t col, HIT_STATUS hit_status, Game & game){
    if (hit_status != HIT_STATUS::KILL){
        wrong_points_.emplace_back(row, col);
        return;
    }
    std::vector<std::pair<uint32_t , uint32_t >> points_of_ship;
    points_of_ship.emplace_back(row, col);
    int32_t direction = 0;
    GameField & rival_field = game.get_rival_gamer_field();
    if (row - 1 > 0 && rival_field(row - 1, col) == 2){
        direction = 1;
    }
    else if (row + 1 <= 10 && rival_field(row + 1, col) == 2){
        direction = 2;
    }
    else if (col - 1 > 'a' && rival_field(row, col - 1) == 2){
        direction = 3;
    }
    else if (col + 1 <= 'j' && rival_field(row, col + 1) == 2){
        direction = 4;
    }
    while (true){
        if (direction == 1 && row - 1 > 0 && rival_field(row - 1, col) == 2){
            row--;
        }
        else if (direction == 2 && row + 1 <= 10 && rival_field(row + 1, col) == 2){
            row++;
        }
        else if (direction == 3 && col - 1 > 'a' && rival_field(row, col - 1) == 2){
            col--;
        }
        else if (direction == 4 && col + 1 <= 'j' && rival_field(row, col + 1) == 2){
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