//
// Created by Андрей Гайдамака on 08.12.2019.
//

#include "with_file_name.h"
#include <cstring>

error::with_file_name::with_file_name() {
    std::memset(this->file_name, 0, sizeof(file_name));
}

void error::with_file_name::set_file_name(const char *filename) {
    if (filename != nullptr){
        strncpy(this->file_name, filename, sizeof(this->file_name));
        this->file_name[sizeof(filename) - 1] = '\0';
    }
    else{
        this->file_name[0] = '\0';
    }
}