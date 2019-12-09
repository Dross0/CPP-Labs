//
// Created by Андрей Гайдамака on 09.12.2019.
//

#include "cant_convert.h"
#include <cstdio>


void error::cant_convert::format_error_message() const {
    snprintf(error_message_buffer, sizeof(error_message_buffer), "Cant convert '%s' to column type, in line %d in file %s .",
            column_content, file_line, file_name);
}