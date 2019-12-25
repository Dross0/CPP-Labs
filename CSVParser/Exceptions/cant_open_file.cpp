//
// Created by Андрей Гайдамака on 08.12.2019.
//

#include "cant_open_file.h"
#include <cstdio>

void error::cant_open_file::format_error_message() const {
    snprintf(error_message_buffer, sizeof(error_message_buffer), "Cant open file: %s .", file_name);
}