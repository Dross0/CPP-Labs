//
// Created by Андрей Гайдамака on 22.11.2019.
//

#ifndef TASK3_GAMEFIELDEXCEPTION_H
#define TASK3_GAMEFIELDEXCEPTION_H
#include <stdexcept>
#include <string>

class GameFieldException : public std::exception {
public:
    explicit GameFieldException(const std::string & m_error);

    const char * what() const noexcept;

protected:
    std::string m_error_;
};


#endif //TASK3_GAMEFIELDEXCEPTION_H
