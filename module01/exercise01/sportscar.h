//
// Created by CTW03389 on 11/11/2024.
//

#ifndef SEA_ME_WARM_UP_SPORTSCAR_H
#define SEA_ME_WARM_UP_SPORTSCAR_H

#include "car.h"

class SportsCar : public Car {
    int c_top_speed {};
public:
    SportsCar() = delete;
    SportsCar(std::string, std::string, int, int); // constructor
    SportsCar(const SportsCar&); // copy constructor
    ~SportsCar() = default; // destructor
    SportsCar& operator = (const SportsCar&);  // copy/assignment operator
    void drive();
};


#endif //SEA_ME_WARM_UP_SPORTSCAR_H
