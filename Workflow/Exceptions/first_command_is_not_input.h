//
// Created by Андрей Гайдамака on 14.12.2019.
//

#ifndef TASK2_FIRST_COMMAND_IS_NOT_INPUT_H
#define TASK2_FIRST_COMMAND_IS_NOT_INPUT_H

#include <stdexcept>
#include <string>

namespace error {
    class first_command_is_not_input : std::exception {
    public:
        explicit first_command_is_not_input(const std::string &error_message);

        const char *what() const noexcept override;

    private:
        std::string err_msg;
    };
}

#endif //TASK2_FIRST_COMMAND_IS_NOT_INPUT_H
