//
// Created by Андрей Гайдамака on 14.12.2019.
//

#include "wrong_command_order.h"

error::wrong_command_order::wrong_command_order(const std::string &error_message) : err_msg(error_message)
{}

const char *error::wrong_command_order::what() const noexcept {
    return err_msg.c_str();
}
