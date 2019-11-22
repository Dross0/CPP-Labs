//
// Created by Андрей Гайдамака on 25.10.2019.
//

/*#ifndef TASK3_CONSOLEGAMER_H
#define TASK3_CONSOLEGAMER_H
#include "IGamer.h"
#include "GameField.h"

class ConsoleGamer: public IGamer{
public:
    ConsoleGamer() = default;

    ~ConsoleGamer() override = default;

    HIT_STATUS make_move(std::shared_ptr<IGamer> rival) override;

    HIT_STATUS get_hit(uint8_t row, uint8_t col) override;

    void place_ships() override;

    bool check_lose() override;

    void print_personal_field() override;

    void print_hits_field() override;

private:
    GameField personal_;
    GameField hits_field_;
};


#endif //TASK3_CONSOLEGAMER_H
*/