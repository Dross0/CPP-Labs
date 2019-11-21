//
// Created by Андрей Гайдамака on 19.11.2019.
//

#include "Game.h"
#include "RandomGamer.h"
#include "ConsoleGamer.h"
#include "OptimalGamer.h"
#include "ConsoleView.h"

Game::Game(Game_config gf) : game_config_(gf)
{}

void Game::play() const {
    ConsoleView CV;
    for (size_t i = 0; i < game_config_.count; ++i) {
        std::shared_ptr<IGamer> gamer1 = make_player(game_config_.gamer1);
        std::shared_ptr<IGamer> gamer2 = make_player(game_config_.gamer2);
        gamer1->place_ships();
        gamer2->place_ships();
        std::map<std::string, unsigned int> gamer1_statistics;
        std::map<std::string, unsigned int> gamer2_statistics;
        HIT_STATUS hit_status;
        while (true) {
            hit_status = gamer1->make_move(gamer2);
            change_statistics(gamer1_statistics, hit_status);
            CV.draw(gamer1, gamer1_statistics, hit_status);
            if (gamer2->check_lose()) {
                std::cout << "Gamer1 win\n";
                break;
            }
            hit_status = gamer2->make_move(gamer1);
            change_statistics(gamer2_statistics, hit_status);
            CV.draw(gamer2, gamer2_statistics, hit_status);
            if (gamer1->check_lose()) {
                std::cout << "Gamer2 win\n";
                break;
            }
        }

    }
}

std::shared_ptr<IGamer> Game::make_player(Gamer_type gamer_type) const {
    std::shared_ptr<IGamer> gamer;
    switch (gamer_type) {
        case Gamer_type::RANDOM_GAMER:
            gamer = std::make_shared<RandomGamer>();
            break;
        case Gamer_type::CONSOLE_GAMER:
            gamer = std::make_shared<ConsoleGamer>();
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