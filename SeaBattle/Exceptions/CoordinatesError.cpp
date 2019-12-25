//
// Created by Андрей Гайдамака on 22.11.2019.
//

#include "CoordinatesError.h"

CoordinatesError::CoordinatesError(const std::string& m_error) : GameFieldException(m_error)
{}

const char * CoordinatesError::what() const noexcept{
    return m_error_.c_str();
}