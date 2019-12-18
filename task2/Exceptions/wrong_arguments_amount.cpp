//
// Created by Андрей Гайдамака on 18.12.2019.
//

#include "wrong_arguments_amount.h"

error::wrong_arguments_amount::wrong_arguments_amount(const std::string &error_message) : err_msg(error_message)
{}

const char* error::wrong_arguments_amount::what() const noexcept{
    return err_msg.c_str();
}