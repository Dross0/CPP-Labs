//
// Created by Андрей Гайдамака on 14.12.2019.
//

#include "cant_get_next_line.h"

error::cant_get_next_line::cant_get_next_line(const std::string &error_message) : err_msg(error_message)
{}

const char *error::cant_get_next_line::what() const noexcept {
    return err_msg.c_str();
}
