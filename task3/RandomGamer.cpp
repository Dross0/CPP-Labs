//
// Created by Андрей Гайдамака on 25.10.2019.
//

#include "RandomGamer.h"
#include <random>

HIT_STATUS RandomGamer::make_move(std::shared_ptr<IGamer> rival) {
    std::default_random_engine generator;
    generator.seed(time(nullptr));
    std::uniform_int_distribution<int> distribution(0, 1000);
    uint8_t row, col;
    do {
        row = 1 + distribution(generator) % 10;
        col = 'a' + distribution(generator) % 10;
    } while (hits_field_(row, col));

    HIT_STATUS status = rival->get_hit(row, col);
    if (status == HIT_STATUS::MISS){
        hits_field_(row, col) = 3;
    }
    else if (status == HIT_STATUS::HIT){
        hits_field_(row, col) = 2;
    }
    else if (status == HIT_STATUS::KILL){
        hits_field_(row, col) = 2;
    }
    return status;
}

HIT_STATUS RandomGamer::get_hit(uint8_t row, uint8_t col) {
    HIT_STATUS status = personal_.hit(row, col);
    return status;
}

bool RandomGamer::check_lose() {
    return 0 == personal_.get_alive_ships_amount();
}

void RandomGamer::place_ships() {
    std::default_random_engine generator;
    generator.seed(time(nullptr));
    std::uniform_int_distribution<int> distribution(0, 1000);
    Direction dirs[] = {Direction::UP, Direction::DOWN, Direction::RIGHT, Direction::LEFT};
    for (uint8_t i = 0; i < 10; ++i){
        try{
            uint8_t row = 1 + distribution(generator) % 10;
            uint8_t col = 'a' + distribution(generator) % 10;
            Direction dir = dirs[distribution(generator) % 4];
            if (i == 0){
                personal_.place(row, col, dir, 4);
            }
            else if (i >= 1 && i <= 2){
                personal_.place(row, col, dir, 3);
            }
            else if (i >= 3 && i <= 5){
                personal_.place(row, col, dir, 2);
            }
            else{
                personal_.place(row, col, dir, 1);
            }
        }
        catch (const std::runtime_error& error){
            i--;
        }
    }
}

void RandomGamer::print_personal_field(){
    personal_.print();
}

void RandomGamer::print_hits_field(){
    hits_field_.print();
}