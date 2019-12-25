//
// Created by Андрей Гайдамака on 08.12.2019.
//

#ifndef TASK4_WITH_FILE_NAME_H
#define TASK4_WITH_FILE_NAME_H


namespace error {
    const unsigned int MAX_FILE_NAME_LEN = 255;

    class with_file_name {
    public:
        with_file_name();

        void set_file_name(const char * filename);

        char file_name[MAX_FILE_NAME_LEN + 1];
    };
}

#endif //TASK4_WITH_FILE_NAME_H
