//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK3_OPTIMALGAMER_H
#define TASK3_OPTIMALGAMER_H
#include "IGamer.h"
#include "GameField.h"
#include "Game.h"
#include <vector>


class OptimalGamer: public IGamer {
public:
    OptimalGamer() = default;

    ~OptimalGamer() override = default;

    std::pair<uint32_t, uint32_t> get_coordinates(Game & game) const override;

    void place_ships(Game & game) override;

    void add_point_to_wrong_points(uint32_t row, uint32_t col, HIT_STATUS hit_status, Game & game) override;
private:
    std::vector< std::pair<uint32_t, uint32_t >> wrong_points_;
};


#endif //TASK3_OPTIMALGAMER_H
