//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK3_CONSOLEGAMER_H
#define TASK3_CONSOLEGAMER_H
#include "IGamer.h"
#include "GameField.h"
#include <vector>

class ConsoleGamer: public IGamer{
public:
    ConsoleGamer() = default;

    ~ConsoleGamer() override = default;

    std::pair<uint32_t, uint32_t> get_coordinates(Game & game) const override;

    void place_ships(Game & game) override;

    void add_point_to_wrong_points(uint32_t row, uint32_t col, HIT_STATUS hit_status, Game & game) override;
private:
    std::vector<std::pair<uint32_t, uint32_t >> wrong_points_;
};


#endif //TASK3_CONSOLEGAMER_H
