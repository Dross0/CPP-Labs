//
// Created by Андрей Гайдамака on 09.12.2019.
//

#include "cant_read_line.h"
#include <cstdio>

void error::cant_read_line::format_error_message() const {
    snprintf(error_message_buffer, sizeof(error_message_buffer), "Cant read next line in file %s .",
            file_name);
}