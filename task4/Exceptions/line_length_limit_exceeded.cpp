//
// Created by Андрей Гайдамака on 08.12.2019.
//

#include "line_length_limit_exceeded.h"

#include <stdio.h>

void error::line_length_limit_exceeded::format_error_message() const {
    snprintf(error_message_buffer, sizeof(error_message_buffer), "Line number %d in file %s exceeds the maximum length");
}