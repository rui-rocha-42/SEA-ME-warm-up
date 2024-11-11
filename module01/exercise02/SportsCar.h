#ifndef SEA_ME_WARM_UP_SPORTSCAR_H
#define SEA_ME_WARM_UP_SPORTSCAR_H

#include "Car.h"

class SportsCar : public Car {
    int c_top_speed {};
public:
    SportsCar() = delete;
    SportsCar(std::string, std::string, int, int); // constructor
    SportsCar(const SportsCar&); // copy constructor
    ~SportsCar() = default; // destructor
    SportsCar& operator = (const SportsCar&);  // copy/assignment operator
    void drive() override;
    int top_speed() const;
    void top_speed(int);
    void start() const override;
    void fuel() override;
};


#endif //SEA_ME_WARM_UP_SPORTSCAR_H
