//
// Created by Андрей Гайдамака on 14.12.2019.
//

#include "cant_open_file.h"

error::cant_open_file::cant_open_file(const std::string &error_message) : err_msg(error_message)
{}

const char *error::cant_open_file::what() const noexcept {
    return err_msg.c_str();
}
