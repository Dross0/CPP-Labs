//
// Created by Андрей Гайдамака on 25.10.2019.
//

#include "ConsoleView.h"


void ConsoleView::draw(std::shared_ptr<IGamer> gamer, std::map<std::string, unsigned int> &stat,
                       HIT_STATUS hit_status) const {
    switch (hit_status) {
        case HIT_STATUS::MISS:
            std::cout << "Промах" << std::endl;
            break;
        case HIT_STATUS::HIT:
            std::cout << "Попадание" << std::endl;
            break;
        case HIT_STATUS::KILL:
            std::cout << "Убийство" << std::endl;
            break;
    }
    std::cout << "Your field:" << std::endl;
    gamer->print_personal_field();
    std::cout << "Your hits field:" << std::endl;
    gamer->print_hits_field();
    unsigned int total = stat["total_number"];
    std::cout << "Statistics: " << std::endl;
    std::cout << " Total - " << total << std::endl;
    std::cout << " Number of misses - " << stat["miss_count"] << std::endl;
    std::cout << " Percent of misses - " << static_cast<double>(stat["miss_count"]) / total * 100 << "%" << std::endl;
    std::cout << " Number of hits - " << stat["hit_count"] << std::endl;
    std::cout << " Percent of hits - " << static_cast<double>(stat["hit_count"]) / total * 100 << "%" << std::endl;
    std::cout << " Number of kills - " << stat["kill_count"] << std::endl;
    scroll(15);
}

void ConsoleView::scroll(unsigned int number_of_lines) const {
    for (unsigned int i = 0; i < number_of_lines; ++i) {
        std::cout << std::endl;
    }
}