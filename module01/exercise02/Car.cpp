#include "Car.h"
#include <utility>
#include <iostream>

Car::Car(std::string make, std::string model, int year):
c_make(std::move(make)), c_model(std::move(model)), c_year(year) {}

Car::Car(const Car& car): c_make(car.c_make), c_model(car.c_model), c_year(car.c_year) {}

Car& Car::operator = (const Car& o) {
    if(this != &o) {
        c_make = o.c_make;
        c_model = o.c_model;
        c_year = o.c_year;
    }
    return *this;
}

std::string Car::make() const {
    return c_make;
}

std::string Car::model() const {
    return c_model;
}

int Car::year() const {
    return c_year;
}

void Car::make(std::string make) {
    c_make = std::move(make);
}

void Car::model(std::string model) {
    c_model = std::move(model);
}

void Car::year(int year) {
    c_year = year;
}

void Car::drive() {
    std::cout << "Driving " + c_make + " " << c_model << " " << c_year << " edition\n";
}
