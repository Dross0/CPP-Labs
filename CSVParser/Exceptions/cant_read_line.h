//
// Created by Андрей Гайдамака on 09.12.2019.
//

#ifndef TASK4_CANT_READ_LINE_H
#define TASK4_CANT_READ_LINE_H
#include "Base.h"
#include "ExceptionsData/with_file_name.h"

namespace error {
    class cant_read_line : public Base, public with_file_name {
        void format_error_message() const override;
    };
}


#endif //TASK4_CANT_READ_LINE_H
