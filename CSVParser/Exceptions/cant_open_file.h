//
// Created by Андрей Гайдамака on 08.12.2019.
//

#ifndef TASK4_CANT_OPEN_FILE_H
#define TASK4_CANT_OPEN_FILE_H
#include "Base.h"
#include "ExceptionsData/with_file_name.h"

namespace error {
    class cant_open_file: public Base, public with_file_name{
    public:
        void format_error_message() const override;
    };
}

#endif //TASK4_CANT_OPEN_FILE_H
