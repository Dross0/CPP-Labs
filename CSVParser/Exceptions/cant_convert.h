//
// Created by Андрей Гайдамака on 09.12.2019.
//

#ifndef TASK4_CANT_CONVERT_H
#define TASK4_CANT_CONVERT_H
#include "Base.h"
#include "ExceptionsData/with_file_name.h"
#include "ExceptionsData/with_file_line.h"
#include "ExceptionsData/with_column_content.h"

namespace error {
    class cant_convert : public Base, public with_file_line, public with_file_name, public with_column_content {
        void format_error_message() const override;
    };
}


#endif //TASK4_CANT_CONVERT_H
