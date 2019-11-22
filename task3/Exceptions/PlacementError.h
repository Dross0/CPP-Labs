//
// Created by Андрей Гайдамака on 22.11.2019.
//

#ifndef TASK3_PLACEMENTERROR_H
#define TASK3_PLACEMENTERROR_H
#include "GameFieldException.h"

class PlacementError: public GameFieldException {
public:
    explicit PlacementError(const std::string &m_error);

    const char * what() const noexcept override;

};


#endif //TASK3_PLACEMENTERROR_H
