#include <iostream>
#include "Car.h"
#include <future>
#include <memory>

int main()
{
    auto car = std::make_unique<Car>();
    car->printParts();
    return 0;
}
