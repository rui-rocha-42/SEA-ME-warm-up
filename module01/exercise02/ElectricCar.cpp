#include <iostream>
#include "ElectricCar.h"

ElectricCar::ElectricCar(std::string make, std::string model, int year):
        Car(std::move(make), std::move(model), year){}

ElectricCar::ElectricCar(const ElectricCar& car): Car(car), c_battery(car.c_battery) {}

ElectricCar& ElectricCar::operator = (const ElectricCar& o) {
    if(this != &o) {
        c_make = o.c_make;
        c_model = o.c_model;
        c_year = o.c_year;
        c_battery = o.c_battery;
    }
    return *this;
}

void ElectricCar::drive() {
    Car::drive();
    c_battery = 0;
    std::cout << "Battery discharged\n";
}

void ElectricCar::start() const {
    std::cout << "Starting ECU\n";
}

void ElectricCar::fuel() {
    c_battery = 100;
    std::cout << "Battery full\n";
}
