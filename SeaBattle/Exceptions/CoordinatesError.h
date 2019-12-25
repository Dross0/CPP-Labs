//
// Created by Андрей Гайдамака on 22.11.2019.
//

#ifndef TASK3_COORDINATESERROR_H
#define TASK3_COORDINATESERROR_H
#include "GameFieldException.h"

class CoordinatesError: public GameFieldException {
public:
    explicit CoordinatesError(const std::string& m_error);

    const char * what() const noexcept override;
};


#endif //TASK3_COORDINATESERROR_H
