#ifndef SEA_ME_WARM_UP_CAR_H
#define SEA_ME_WARM_UP_CAR_H

#include <string>
#include "Engine.h"
#include "Wheel.h"
#include "Brake.h"
#include "Transmission.h"

class Car {
public:
    Car();
    ~Car();
    void printParts();

private:
    Engine* engine_;
    Wheel* wheels_;
    Brake* brakes_;
    Transmission* transmission_;
};

#endif //SEA_ME_WARM_UP_CAR_H
