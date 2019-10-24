//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_IWORKER_H
#define TASK2_IWORKER_H
#include <string>
#include <vector>

class IWorker {
public:
    virtual std::vector<std::string> execute() = 0;
    virtual ~IWorker() = default;
};


#endif //TASK2_IWORKER_H
