//
// Created by Андрей Гайдамака on 14.12.2019.
//

#ifndef TASK2_WRONG_COMMAND_ORDER_H
#define TASK2_WRONG_COMMAND_ORDER_H

#include <string>
#include <exception>

namespace error {
    class wrong_command_order : std::exception {
    public:
        wrong_command_order(const std::string& error_message);

        const char * what() const noexcept override;
    private:
        std::string err_msg;
    };
}

#endif //TASK2_WRONG_COMMAND_ORDER_H
