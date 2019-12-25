//
// Created by Андрей Гайдамака on 14.12.2019.
//

#include "first_command_is_not_input.h"

error::first_command_is_not_input::first_command_is_not_input(const std::string &error_message) : err_msg(error_message)
{}

const char *error::first_command_is_not_input::what() const noexcept {
    return err_msg.c_str();
}

