//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_WRITEFILE_H
#define TASK2_WRITEFILE_H

#include "ICommand.h"
#include <fstream>

class WriteFile : public ICommand {
public:
    explicit WriteFile(std::vector<std::string>& args);

    ~WriteFile() override ;

    std::vector<std::string> execute(std::vector<std::string>& data) override;

    COMMAND_TYPE get_command_type() const noexcept override;
private:
    std::ofstream file_;
};


#endif //TASK2_WRITEFILE_H
