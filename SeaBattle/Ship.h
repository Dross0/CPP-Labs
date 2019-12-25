//
// Created by Андрей Гайдамака on 04.11.2019.
//

#ifndef TASK3_SHIP_H
#define TASK3_SHIP_H
#include <cstdint>
#include <bitset>


enum class Direction : uint8_t {
    DOWN,
    UP,
    LEFT,
    RIGHT
};


class Ship {
public:
    Ship(uint8_t row, uint8_t col, Direction dir, uint8_t len);

    ~Ship() = default;

    std::pair<uint8_t, uint8_t> get_coordinates() const;

    Direction get_dir() const;

    uint8_t get_len() const;

    bool is_ship(int8_t row, int8_t col) const;

    bool hit(int8_t row, int8_t col);

    bool is_dead() const;

    bool inside_area(int8_t row, int8_t col);
private:
    std::pair<uint8_t, uint8_t > coordinates_;
    Direction dir_;
    uint8_t len_;
    uint8_t hits_;
};


#endif //TASK3_SHIP_H
