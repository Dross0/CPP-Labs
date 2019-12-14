//
// Created by Андрей Гайдамака on 14.12.2019.
//

#ifndef TASK2_MIDDLE_COMMAND_IS_NOT_PROCESSING_H
#define TASK2_MIDDLE_COMMAND_IS_NOT_PROCESSING_H

#include <stdexcept>
#include <string>

namespace error {
    class middle_command_is_not_processing : std::exception {
    public:
        explicit middle_command_is_not_processing(const std::string &error_message);

        const char *what() const noexcept override;

    private:
        std::string err_msg;
    };
}

#endif //TASK2_MIDDLE_COMMAND_IS_NOT_PROCESSING_H
