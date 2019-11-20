//
// Created by Андрей Гайдамака on 19.11.2019.
//

#include "Game.h"
#include "RandomGamer.h"
#include "ConsoleGamer.h"
#include "OptimalGamer.h"
#include "ConsoleView.h"

Game::Game(Gamer_type gamer1_type, Gamer_type gamer2_type) {
    switch (gamer1_type) {
        case Gamer_type::RANDOM_GAMER:
            gamer1_ = std::make_shared<RandomGamer>();
            break;
        case Gamer_type::CONSOLE_GAMER:
            gamer1_ = std::make_shared<ConsoleGamer>();
            break;
        case Gamer_type::OPTIMAL_GAMER:
            gamer1_ = std::make_shared<OptimalGamer>();
            break;
    }
    switch (gamer2_type) {
        case Gamer_type::RANDOM_GAMER:
            gamer2_ = std::make_shared<RandomGamer>();
            break;
        case Gamer_type::CONSOLE_GAMER:
            gamer2_ = std::make_shared<ConsoleGamer>();
            break;
        case Gamer_type::OPTIMAL_GAMER:
            gamer2_ = std::make_shared<OptimalGamer>();
            break;
    }
}

void Game::play() const {
    gamer1_->place_ships();
    gamer2_->place_ships();
    std::map<std::string, unsigned int> gamer1_statistics;
    std::map<std::string, unsigned int> gamer2_statistics;
    HIT_STATUS hit_status;
    ConsoleView CV;
    while (true) {
        hit_status = gamer1_->make_move(gamer2_);
        change_statistics(gamer1_statistics, hit_status);
        CV.draw(gamer1_, gamer1_statistics, hit_status);
        if (gamer2_->check_lose()) {
            std::cout << "Gamer1 win\n";
            break;
        }
        hit_status = gamer2_->make_move(gamer1_);
        change_statistics(gamer2_statistics, hit_status);
        CV.draw(gamer2_, gamer2_statistics, hit_status);
        if (gamer1_->check_lose()) {
            std::cout << "Gamer2 win\n";
            break;
        }
    }
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