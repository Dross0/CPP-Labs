//
// Created by Андрей Гайдамака on 19.11.2019.
//

#include "Game.h"
#include "RandomGamer.h"
#include "ConsoleGamer.h"
#include "OptimalGamer.h"
#include "ConsoleView.h"

Game::Game(Game_config gf) : game_config_(gf){
    current_gamer_number_ = Gamer_number::FIRST;
}

HIT_STATUS Game::make_move(uint32_t row, uint32_t col){
    HIT_STATUS status = get_rival_gamer_field().hit(row, col);
    return status;
}

bool Game::check_rival_lose(){
    return 0 == get_rival_gamer_field().get_alive_ships_amount();
}

GameField & Game::get_current_gamer_field(){
    if (current_gamer_number_ == Gamer_number::FIRST){
        return gamer1_field_;
    }
    else if (current_gamer_number_ == Gamer_number::SECOND){
        return gamer2_field_;
    }
}

GameField & Game::get_rival_gamer_field(){
    if (current_gamer_number_ == Gamer_number::FIRST){
        return gamer2_field_;
    }
    else if (current_gamer_number_ == Gamer_number::SECOND){
        return gamer1_field_;
    }
}


void Game::play() {
    ConsoleView CV;
    for (size_t i = 0; i < game_config_.count; ++i) {
        std::shared_ptr<IGamer> gamer1 = make_player(game_config_.gamer1);
        std::shared_ptr<IGamer> gamer2 = make_player(game_config_.gamer2);
        std::shared_ptr<IGamer> current_gamer = gamer1;
        current_gamer_number_ = Gamer_number::FIRST;
        gamer1->place_ships(*this);
        get_current_gamer_field().print();
        current_gamer_number_ = Gamer_number::SECOND;
        gamer2->place_ships(*this);
        get_current_gamer_field().print();
        current_gamer_number_ = Gamer_number::FIRST;
        std::map<std::string, unsigned int> gamer1_statistics;
        std::map<std::string, unsigned int> gamer2_statistics;
        HIT_STATUS hit_status;
        while (true) {
            std::pair<uint32_t, uint32_t > coordinates = current_gamer->get_coordinates(*this);
            hit_status = make_move(coordinates.first, coordinates.second);
            current_gamer->add_point_to_wrong_points(coordinates.first, coordinates.second, hit_status, *this);
            if (current_gamer_number_ == Gamer_number::FIRST){
                change_statistics(gamer1_statistics, hit_status);
            }
            else{
                change_statistics(gamer2_statistics, hit_status);
            }
            CV.draw(*this, (current_gamer_number_ == Gamer_number::FIRST ? gamer1_statistics : gamer2_statistics), hit_status);
            if (hit_status == HIT_STATUS::KILL || hit_status == HIT_STATUS::HIT){
                if (check_rival_lose()){
                    std::cout << ((current_gamer_number_ == Gamer_number::FIRST) ? "Gamer1 победил!" : "Gamer2 победил!") << std::endl;
                    break;
                }
            }
            else{
                current_gamer_number_ = (current_gamer_number_ == Gamer_number::FIRST) ? Gamer_number::SECOND : Gamer_number::FIRST;
                current_gamer = (current_gamer == gamer1) ? gamer2 : gamer1;
            }
        }
        gamer1_field_.clear();
        gamer2_field_.clear();
    }
}

std::shared_ptr<IGamer> Game::make_player(Gamer_type gamer_type) const {
    std::shared_ptr<IGamer> gamer;
    switch (gamer_type) {
        case Gamer_type::RANDOM_GAMER:
            gamer = std::make_shared<RandomGamer>();
            break;
        case Gamer_type::CONSOLE_GAMER:
            //gamer = std::make_shared<ConsoleGamer>();
            break;
        case Gamer_type::OPTIMAL_GAMER:
            gamer = std::make_shared<OptimalGamer>();
            break;
    }
    return gamer;
}

void Game::change_statistics(std::map<std::string, unsigned int> &stats, HIT_STATUS hit_status) const {
    switch (hit_status) {
        case HIT_STATUS::MISS:
            stats["miss_count"]++;
            break;
        case HIT_STATUS::HIT:
            stats["hit_count"]++;
            break;
        case HIT_STATUS::KILL:
            stats["hit_count"]++;
            stats["kill_count"]++;
            break;
    }
    stats["total_number"]++;
}