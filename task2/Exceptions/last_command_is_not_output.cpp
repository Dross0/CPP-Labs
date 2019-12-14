//
// Created by Андрей Гайдамака on 14.12.2019.
//

#include "last_command_is_not_output.h"

error::last_command_is_not_output::last_command_is_not_output(const std::string &error_message) : err_msg(error_message)
{}

const char * error::last_command_is_not_output::what() const noexcept {
    return err_msg.c_str();
}
