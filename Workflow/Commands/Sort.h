//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_SORT_H
#define TASK2_SORT_H

#include "ICommand.h"

class Sort : public ICommand {
public:
    explicit Sort(std::vector<std::string>& args);

    std::vector<std::string> execute(std::vector<std::string>& data) override ;

    COMMAND_TYPE get_command_type() const noexcept override;
};


#endif //TASK2_SORT_H
