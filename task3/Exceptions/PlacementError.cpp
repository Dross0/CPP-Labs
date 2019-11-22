//
// Created by Андрей Гайдамака on 22.11.2019.
//

#include "PlacementError.h"

PlacementError::PlacementError(const std::string &m_error) : GameFieldException(m_error)
{}

const char* PlacementError::what() const noexcept {
    return m_error_.c_str();
}
