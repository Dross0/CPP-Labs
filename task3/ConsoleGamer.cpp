//
// Created by Андрей Гайдамака on 25.10.2019.
//

/*#include "ConsoleGamer.h"

HIT_STATUS ConsoleGamer::make_move(std::shared_ptr<IGamer> rival) {
    uint32_t row = 0;
    uint8_t col = 0;
    std::cout << "Введите координаты: " << std::endl << "Row: ";
    std::cin >> row;
    std::cout << "Col: ";
    std::cin >> col;
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

HIT_STATUS ConsoleGamer::get_hit(uint8_t row, uint8_t col) {
    HIT_STATUS status = personal_.hit(row, col);
    return status;
}

bool ConsoleGamer::check_lose() {
    return 0 == personal_.get_alive_ships_amount();
}

void ConsoleGamer::place_ships() {
    Direction dirs[] = {Direction::UP, Direction::DOWN, Direction::RIGHT, Direction::LEFT};
    uint8_t ships[] = {4, 3, 2, 1};
    for (uint8_t i = 0; i < 10; ++i){
        int row = 0;
        uint8_t col = 0;
        int dir_index = 0;
        int len = 0;
        std::cout << "Введите координаты: " << std::endl << "Row: ";
        std::cin >> row;
        std::cout << "Col: ";
        std::cin >> col;
        std::cout << "Len: ";
        std::cin >> len;
        std::cout << "Dir: ";
        std::cin >> dir_index;
        if (len > 4){
            std::cout <<  (len > 4);
            std::cout << "Wrong length!" << len << std::endl;
            i--;
            continue;
        }
        if (!ships[len-1]){
            std::cout << "You already place all ships with length=" << len << std::endl;
            i--;
            continue;
        }
        if (dir_index < 0 || dir_index > 3){
            std::cout << "Wrong direction!" << std::endl;
            i--;
            continue;
        }
        try{
            personal_.place(row, col, dirs[dir_index - 1], len);
        }
        catch (const std::runtime_error& error){
            i--;
            std::cout << error.what() << std::endl;
            continue;
        }
        ships[len-1]--;
    }
}

void ConsoleGamer::print_personal_field(){
    personal_.print();
}

void ConsoleGamer::print_hits_field(){
    hits_field_.print();
}
 */