//
// Created by Андрей Гайдамака on 25.10.2019.
//

#include "GameField.h"
#include <iostream>
GameField::GameField() {
    map_ = new uint8_t[10 * 10];
    for (size_t row = 0; row < 100; ++row){
        map_[row] = Cell_status::CLEAR;
    }
}

GameField::~GameField() {
    delete [] map_;
}

uint8_t& GameField::operator()(int32_t row, int32_t col) {
    row -= 1;
    col -= 'a';
    if (row >= 10 || row < 0 || col >= 10 || col < 0){
        std::cout << row << " " << col << std::endl;
        throw std::invalid_argument("Wrong point!");
    }
    return map_[row * 10 + col];
}

uint8_t GameField::operator()(int32_t row, int32_t col) const {
    row -= 1;
    col -= 'a';
    if (row >= 10 || row < 0 || col >= 10 || col < 0){
        throw std::invalid_argument("Wrong point!");
    }
    return map_[row * 10 + col];
}

void GameField::place(int32_t row, int32_t col, Direction dir, uint8_t len) {
    row -= 1;
    col -= 'a';
    if (row >= 10 || row < 0 || col >= 10 || col < 0){
        throw std::invalid_argument("Wrong point!");
    }
    if ((dir == Direction::RIGHT && col + len - 1 > 9) || (dir == Direction::LEFT && col - len - 1 < 0)){
            throw std::runtime_error("Cant place here!");  //change
    }
    if ((dir == Direction::DOWN && row + len - 1 > 9) || (dir == Direction::UP && row - len - 1 < 0)){
        throw std::runtime_error("Cant place here!");  //change
    }
    size_t ships_amount = ships_.size();
    for (size_t k = 0; k < ships_amount; ++k){
        if (ships_[k].is_ship(row, col)){
            throw std::runtime_error("Cant place here! (is ship)");  //change
        }
    }
    int8_t inc = (dir == Direction::RIGHT || dir == Direction::DOWN) ? 1 : -1;
    bool right_left = (dir == Direction::RIGHT || dir == Direction::LEFT);
    uint8_t l = 0;
    uint8_t tmp_col = col;
    uint8_t tmp_row = row;
    while (l < len){
        for (auto ship: ships_){
            if (ship.inside_area(tmp_row, tmp_col)){
                throw std::runtime_error("Cant place here! (So close)");
            }
        }
        if (right_left){
            tmp_col += inc;
        }
        else{
            tmp_row += inc;
        }
        l++;
    }
    tmp_col = col;
    tmp_row = row;
    uint8_t k = 0;
    while (k < len){
        map_[tmp_row * 10 + tmp_col] = Cell_status::SHIP;
        if (right_left){
            tmp_col += inc;
        }
        else{
            tmp_row += inc;
        }
        k++;
    }
    ships_.emplace_back(row, col, dir, len);
}

HIT_STATUS GameField::hit(int32_t row, int32_t col) {
    row -= 1;
    col -= 'a';
    if (row >= 10 || row < 0 || col >= 10 || col < 0){
        throw std::invalid_argument("Wrong point!");
    }
    size_t ships_amount = ships_.size();
    HIT_STATUS status = HIT_STATUS::MISS;
    if (map_[row * 10 + col] != Cell_status::CLEAR && map_[row * 10 + col] != Cell_status::SHIP){
        return status;
    }
    map_[row * 10 + col] = Cell_status::MISS;
    for (size_t i = 0; i < ships_amount; ++i){
        if (ships_[i].hit(row, col)) {
            status = (ships_[i].is_dead()) ? HIT_STATUS::KILL : HIT_STATUS::HIT;
            map_[row * 10 + col] = Cell_status::DAMAGED_SHIP;
            break;
        }
    }
    return status;
}

int GameField::get_alive_ships_amount(){
    int count = 0;
    for (auto ship: ships_){
        if (!ship.is_dead()){
            count++;
        }
    }
    return count;
}

void GameField::print() const {
    for (int row = 0; row < 10; ++row){
        for (int col = 0; col < 10; ++col){
            char symbol = '.';
            if (map_[row * 10 + col] == Cell_status::SHIP){
                symbol = '@';
            }
            else if (map_[row * 10 + col] == Cell_status::DAMAGED_SHIP){
                symbol = 'X';
            }
            else if (map_[row * 10 + col] == Cell_status::MISS){
                symbol = 'o';
            }
            std::cout << symbol << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void GameField::clear() {
    for (uint8_t row = 0; row < 10; ++row){
        for (uint8_t col = 0; col < 10; ++col){
            map_[row * 10 + col] = Cell_status::CLEAR;
        }
    }
    ships_.clear();
}

