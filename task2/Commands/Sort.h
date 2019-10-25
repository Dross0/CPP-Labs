//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_SORT_H
#define TASK2_SORT_H

#include "IWorker.h"

class Sort : public IWorker {
public:
    explicit Sort(std::vector<std::string>& args);

    std::vector<std::string> execute(std::vector<std::string>& data) override ;

};


#endif //TASK2_SORT_H
