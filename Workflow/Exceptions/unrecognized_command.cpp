//
// Created by Андрей Гайдамака on 14.12.2019.
//

#include "unrecognized_command.h"

error::unrecognized_command::unrecognized_command(const std::string &error_message) : err_msg(error_message)
{}

const char *error::unrecognized_command::what() const noexcept {
    return err_msg.c_str();
}
