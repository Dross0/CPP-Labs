//
// Created by Андрей Гайдамака on 14.12.2019.
//

#include "missed_end_of_command_block.h"

error::missed_end_of_command_block::missed_end_of_command_block(const std::string &error_message) : err_msg(error_message)
{}

const char *error::missed_end_of_command_block::what() const noexcept {
    return err_msg.c_str();
}
