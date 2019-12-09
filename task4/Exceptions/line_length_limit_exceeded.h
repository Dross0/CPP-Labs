//
// Created by Андрей Гайдамака on 08.12.2019.
//

#ifndef TASK4_LINE_LENGTH_LIMIT_EXCEEDED_H
#define TASK4_LINE_LENGTH_LIMIT_EXCEEDED_H
#include "Base.h"
#include "with_file_name.h"
#include "with_file_line.h"

namespace error {
    class line_length_limit_exceeded : public Base, public with_file_name, public with_file_line{
        void format_error_message() const override;
    };
}


#endif //TASK4_LINE_LENGTH_LIMIT_EXCEEDED_H
