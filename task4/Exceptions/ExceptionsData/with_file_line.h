//
// Created by Андрей Гайдамака on 08.12.2019.
//

#ifndef TASK4_WITH_FILE_LINE_H
#define TASK4_WITH_FILE_LINE_H

namespace error {
    class with_file_line {
    public:
        with_file_line();

        void set_file_line(int fileline);

        int file_line;
    };
}


#endif //TASK4_WITH_FILE_LINE_H
