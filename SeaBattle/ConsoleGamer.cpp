//
// Created by Андрей Гайдамака on 25.10.2019.
//

#include "ConsoleGamer.h"
#include "Exceptions/PlacementError.h"

std::pair<uint32_t, uint32_t> ConsoleGamer::get_coordinates(Game & game) const {
    uint32_t row = 0;
    uint8_t col = 0;
    std::cout << "Введите координаты: " << std::endl << "Row: ";
    std::cin >> row;
    std::cout << "Col: ";
    std::cin >> col;
    return {row, col};
}


void ConsoleGamer::place_ships(Game & game) {
    Direction dirs[] = {Direction::UP, Direction::DOWN, Direction::RIGHT, Direction::LEFT};
    uint8_t ships[] = {4, 3, 2, 1};
    for (uint8_t i = 0; i < 10; ++i){
        uint32_t row = 0;
        unsigned char col = 0;
        int dir_index = 0;
        int len = 0;
        std::cout << "Введите координаты: " << std::endl << "Row: ";
        std::cin >> row;
        std::cout << "Col: ";
        std::cin >> col;
        std::cout << "Len: ";
        std::cin >> len;
        std::cout << "Dir: ";
        std::cin >> dir_index;
        if (len > 4){
            std::cout <<  (len > 4);
            std::cout << "Wrong length!" << len << std::endl;
            i--;
            continue;
        }
        if (!ships[len-1]){
            std::cout << "You already place all ships with length=" << len << std::endl;
            i--;
            continue;
        }
        if (dir_index < 0 || dir_index > 3){
            std::cout << "Wrong direction!" << std::endl;
            i--;
            continue;
        }
        try{
            game.get_current_gamer_field().place(row, col, dirs[dir_index - 1], len);
        }
        catch (const PlacementError& error){
            std::cout << error.what() << std::endl;
            i--;
            continue;
        }
        ships[len-1]--;
    }
}

void ConsoleGamer::add_point_to_wrong_points(uint32_t row, uint32_t col, HIT_STATUS hit_status, Game & game){
    wrong_points_.emplace_back(row, col);
}

