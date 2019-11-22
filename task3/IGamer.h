//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK3_IGAMER_H
#define TASK3_IGAMER_H
#include <cstdint>
#include "GameField.h"
#include "Game.h"

class Game;

class IGamer {
public:
    virtual ~IGamer() = default;
    virtual std::pair<uint32_t, uint32_t > get_coordinates(Game & game) const = 0;
    virtual void place_ships(Game & game) = 0;
    virtual void add_point_to_wrong_points(uint32_t row, uint32_t col, HIT_STATUS hit_status, Game & game) = 0;
};


#endif //TASK3_IGAMER_H
