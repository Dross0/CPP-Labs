//
// Created by Андрей Гайдамака on 08.12.2019.
//

#include "Base.h"

const char* error::Base::what() const noexcept {
    format_error_message();
    return error_message_buffer;
}