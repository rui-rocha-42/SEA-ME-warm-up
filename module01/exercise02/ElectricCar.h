#ifndef SEA_ME_WARM_UP_ELECTRICCAR_H
#define SEA_ME_WARM_UP_ELECTRICCAR_H

#include "Car.h"

// [INHERITANCE]
class ElectricCar: public Car {
    int c_battery {};
public:
    ElectricCar() = delete;
    ElectricCar(std::string, std::string, int); // constructor
    ElectricCar(const ElectricCar&); // copy constructor
    ~ElectricCar() = default; // destructor
    ElectricCar& operator = (const ElectricCar&);  // copy/assignment operator
    void drive() override;
    void start() const override;
    void fuel() override;
};


#endif //SEA_ME_WARM_UP_ELECTRICCAR_H
