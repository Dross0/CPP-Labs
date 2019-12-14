//
// Created by Андрей Гайдамака on 14.12.2019.
//

#ifndef TASK2_MISSED_START_OF_COMMAND_BLOCK_H
#define TASK2_MISSED_START_OF_COMMAND_BLOCK_H

#include <exception>
#include <string>

namespace error {
    class missed_start_of_command_block : std::exception{
    public:
        missed_start_of_command_block(const std::string& error_message);

        const char * what() const noexcept override;
    private:
        std::string err_msg;
    };
}

#endif //TASK2_MISSED_START_OF_COMMAND_BLOCK_H
