//
// Created by Андрей Гайдамака on 08.12.2019.
//

#ifndef TASK4_BASE_H
#define TASK4_BASE_H
#include <exception>

namespace error {
    class Base : std::exception {
    public:
        virtual void format_error_message() const = 0;

        const char * what() const noexcept override;

        mutable char error_message_buffer[512];
    };
}


#endif //TASK4_BASE_H
