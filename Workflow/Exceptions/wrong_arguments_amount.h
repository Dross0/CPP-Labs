//
// Created by Андрей Гайдамака on 18.12.2019.
//

#ifndef TASK2_WRONG_ARGUMENTS_AMOUNT_H
#define TASK2_WRONG_ARGUMENTS_AMOUNT_H

#include <exception>
#include <string>

namespace error {
    class   wrong_arguments_amount : std::exception {
    public:
        wrong_arguments_amount(const std::string& error_message);

        const char * what() const noexcept override;

    private:
        std::string err_msg;
    };
}


#endif //TASK2_WRONG_ARGUMENTS_AMOUNT_H
