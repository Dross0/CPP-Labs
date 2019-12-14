//
// Created by Андрей Гайдамака on 14.12.2019.
//

#ifndef TASK2_WRONG_COMMAND_FORMAT_H
#define TASK2_WRONG_COMMAND_FORMAT_H

#include <exception>
#include <string>

namespace error {
    class wrong_command_format : std::exception {
    public:
        wrong_command_format(const std::string& error_message);

        const char * what() const noexcept override;

    private:
        std::string err_msg;
    };
}


#endif //TASK2_WRONG_COMMAND_FORMAT_H
