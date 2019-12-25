//
// Created by Андрей Гайдамака on 22.10.2019.
//

#ifndef TASK2_ICOMMAND_H
#define TASK2_ICOMMAND_H
#include <string>
#include <vector>

enum class COMMAND_TYPE{
    INPUT,
    PROCESSING,
    OUTPUT,
};

class ICommand {
public:
    virtual std::vector<std::string> execute(std::vector<std::string>& data) = 0;
    virtual COMMAND_TYPE get_command_type() const noexcept = 0;
    virtual ~ICommand() = default;
};


#endif //TASK2_ICOMMAND_H
