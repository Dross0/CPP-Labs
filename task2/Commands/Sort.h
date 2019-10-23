//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_SORT_H
#define TASK2_SORT_H

#include "IWorker.h"

class Sort : public IWorker {
public:
    Sort(std::vector<std::string>& data, std::vector<std::string>& args);

    std::vector<std::string> execute();

private:
    std::vector<std::string> data_;
};


#endif //TASK2_SORT_H
