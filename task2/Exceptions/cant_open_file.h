//
// Created by Андрей Гайдамака on 14.12.2019.
//

#ifndef TASK2_CANT_OPEN_FILE_H
#define TASK2_CANT_OPEN_FILE_H

#include <exception>
#include <string>

namespace error {
    class cant_open_file : std::exception {
    public:
        cant_open_file(const std::string& error_message);

        const char * what() const noexcept override;
    private:
        std::string err_msg;
    };
}


#endif //TASK2_CANT_OPEN_FILE_H
