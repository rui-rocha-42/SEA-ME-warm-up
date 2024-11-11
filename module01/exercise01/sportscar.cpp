#include "sportscar.h"
#include <utility>
#include <iostream>

SportsCar::SportsCar(std::string make, std::string model, int year, int top_speed):
        Car(std::move(make), std::move(model), year), c_top_speed(top_speed) {}

SportsCar::SportsCar(const SportsCar& car): Car(car), c_top_speed(car.c_year) {}

SportsCar& SportsCar::operator = (const SportsCar& o) {
    if(this != &o) {
        c_make = o.c_make;
        c_model = o.c_model;
        c_year = o.c_year;
        c_top_speed = o.c_top_speed;
    }
    return *this;
}

void SportsCar::drive() {
    Car::drive();
    std::cout << "Top speed " << c_top_speed << "\n";
}
