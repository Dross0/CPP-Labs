//
// Created by Андрей Гайдамака on 14.12.2019.
//

#include "multiply_makers.h"

error::multiply_makers::multiply_makers(const std::string &error_message) : err_msg(error_message)
{}

const char *error::multiply_makers::what() const noexcept {
    return err_msg.c_str();
}
