//
// Created by Андрей Гайдамака on 04.11.2019.
//

#include "Ship.h"
#include <cstdlib>


Ship::Ship(uint8_t row, uint8_t col, Direction dir, uint8_t len) {
    coordinates_ = {row, col};
    dir_ = dir;
    len_ = len;
    hits_ = 0;
}

std::pair<uint8_t, uint8_t> Ship::get_coordinates() const {
    return coordinates_;
}

Direction Ship::get_dir() const {
    return dir_;
}

uint8_t Ship::get_len() const {
    return len_;
}

bool Ship::is_dead() const {
    return hits_ >= len_;
}

bool Ship::is_ship(int8_t row, int8_t col) const {
    if (dir_ == Direction::LEFT || dir_ == Direction::RIGHT){
        if (row != coordinates_.first){
            return false;
        }
        col -= coordinates_.second;
        if ((dir_ == Direction::LEFT && col > 0) || (dir_ == Direction::RIGHT && col < 0)){
            return false;
        }
        col = (col >= 0) ? col : -col;
        return col < len_;
    }
    if (col != coordinates_.second){
        return false;
    }
    row -= coordinates_.first;
    if ((dir_ == Direction::UP && row > 0) || (dir_ == Direction::DOWN && row < 0)){
        return false;
    }
    row = (row >= 0) ? row : -row;
    return row < len_;
}

bool Ship::hit(int8_t row, int8_t col) {
    if (dir_ == Direction::LEFT || dir_ == Direction::RIGHT){
        if (row != coordinates_.first){
            return false;
        }
        col -= coordinates_.second;
        if ((dir_ == Direction::LEFT && col > 0) || (dir_ == Direction::RIGHT && col < 0)){
            return false;
        }
        col = (col >= 0) ? col : -col;
        if (col >= len_){
            return false;
        }
        hits_++;
        return true;
    }
    if (col != coordinates_.second){
        return false;
    }
    row -= coordinates_.first;
    if ((dir_ == Direction::UP && row > 0) || (dir_ == Direction::DOWN && row < 0)){
        return false;
    }
    row = (row >= 0) ? row : -row;
    if (row >= len_){
        return false;
    }
    hits_++;
    return true;
}

bool Ship::inside_area(int8_t row, int8_t col) {
    uint8_t row_tmp = coordinates_.first;
    uint8_t col_tmp = coordinates_.second;
    for (int i = 0; i < len_; ++i){
        int8_t inc = (dir_ == Direction::LEFT || dir_ == Direction::UP) ? -1 : 1;
        if (std::abs(row_tmp - row) <= 1 && std::abs(col_tmp - col) <= 1){
            return true;
        }
        if (dir_ == Direction::LEFT || dir_ == Direction::RIGHT){
            col_tmp += inc;
        }
        else{
            row_tmp += inc;
        }
    }
    return false;
}