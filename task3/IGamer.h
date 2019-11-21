//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK3_IGAMER_H
#define TASK3_IGAMER_H
#include <cstdint>
#include "GameField.h"


class IGamer {
public:
    virtual ~IGamer() = default;
    virtual HIT_STATUS make_move(std::shared_ptr<IGamer> rival) = 0;
    virtual HIT_STATUS get_hit(uint8_t row, uint8_t col) = 0;
    virtual bool check_lose() = 0;
    virtual void place_ships() = 0;
    virtual void print_personal_field() = 0;
    virtual void print_hits_field() = 0;
};


#endif //TASK3_IGAMER_H
