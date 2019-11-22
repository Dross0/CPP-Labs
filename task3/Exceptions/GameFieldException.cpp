//
// Created by Андрей Гайдамака on 22.11.2019.
//

#include "GameFieldException.h"

GameFieldException::GameFieldException(const std::string & m_error) : m_error_(m_error)
{}

const char* GameFieldException::what() const noexcept{
    return m_error_.c_str();
}