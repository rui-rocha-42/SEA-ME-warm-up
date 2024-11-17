#include "Car.h"

Car::Car() {
    engine_ = new Engine();
    wheels_ = new Wheel[4];
    brakes_ = new Brake[4];
    transmission_ = new Transmission();
}

void Car::printParts() {
    engine_->print();
    for (int i = 0; i < 4; ++i) {
        wheels_[i].print();
        brakes_[i].print();
    }
    transmission_->print();
}

Car::~Car() {
    delete engine_;
    delete [] wheels_;
    delete [] brakes_;
    delete transmission_;
}
