//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK2_IBLOCKMAKER_H
#define TASK2_IBLOCKMAKER_H
#include <string>
#include <vector>
#include "Commands/ICommand.h"

class IBlockMaker {
public:
    virtual ~IBlockMaker() = default;
    virtual ICommand * create(std::vector<std::string>& args) = 0;
};


#endif //TASK2_IBLOCKMAKER_H
