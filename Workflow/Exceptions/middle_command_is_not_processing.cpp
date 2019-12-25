//
// Created by Андрей Гайдамака on 14.12.2019.
//

#include "middle_command_is_not_processing.h"

error::middle_command_is_not_processing::middle_command_is_not_processing(const std::string &error_message) : err_msg(error_message)
{}

const char *error::middle_command_is_not_processing::what() const noexcept {
    return err_msg.c_str();
}
