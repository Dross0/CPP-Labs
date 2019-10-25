//
// Created by Андрей Гайдамака on 25.10.2019.
//

#ifndef TASK2_IBLOCKMAKER_H
#define TASK2_IBLOCKMAKER_H
#include <string>
#include <vector>
#include "Commands/IWorker.h"

class IBlockMaker {
public:
    virtual ~IBlockMaker() = default;
    virtual IWorker * create(std::vector<std::string>& args) = 0;
};


#endif //TASK2_IBLOCKMAKER_H
