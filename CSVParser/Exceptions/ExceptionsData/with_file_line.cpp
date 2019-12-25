//
// Created by Андрей Гайдамака on 08.12.2019.
//

#include "with_file_line.h"

error::with_file_line::with_file_line() {
    this->file_line = -1;
}

void error::with_file_line::set_file_line(int fileline) {
    this->file_line = fileline;
}