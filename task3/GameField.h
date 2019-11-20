//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK3_GAMEFIELD_H
#define TASK3_GAMEFIELD_H
#include <cstdint>
#include <stdexcept>
#include <vector>
#include "Ship.h"
#include <iostream>

enum class HIT_STATUS : unsigned int{
    MISS,
    HIT,
    KILL
};

class GameField {
public:
    GameField();

    ~GameField();

    uint8_t& operator()(int32_t row, int32_t col);

    uint8_t operator()(int32_t row, int32_t col) const;

    void place(int32_t row, int32_t col, Direction dir, uint8_t len);

    HIT_STATUS hit(int32_t row, int32_t col);

    int get_alive_ships_amount();

    void print() const;
private:
    uint8_t * map_;
    std::vector<Ship> ships_;
};


#endif //TASK3_GAMEFIELD_H
