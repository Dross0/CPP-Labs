//
// Created by Андрей Гайдамака on 14.12.2019.
//

#include "wrong_command_format.h"

error::wrong_command_format::wrong_command_format(const std::string &error_message) : err_msg(error_message)
{}

const char *error::wrong_command_format::what() const noexcept {
    return err_msg.c_str();
}
