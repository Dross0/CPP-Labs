//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK3_IGAMEVIEW_H
#define TASK3_IGAMEVIEW_H
#include <map>
#include <memory>
#include <string>
#include "IGamer.h"

class IGameView {
public:
    virtual ~IGameView() = default;
    virtual void
    draw(Game& game, std::map<std::string, unsigned int> &stat, HIT_STATUS hit_status) const = 0;
};


#endif //TASK3_IGAMEVIEW_H
