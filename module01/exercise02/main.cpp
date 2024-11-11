#include <iostream>
#include "SportsCar.h"
#include "ElectricCar.h"
#include <future>
#include <memory>

int main()
{
    ElectricCar electric {"BMW", "i4", 2020};
    SportsCar sports {"Mercedes", "M4", 2022, 350};
    SportsCar car3 = sports;
    car3.year(2023);
    car3.top_speed(200);

    Car* cars[] {&electric, &sports, &car3};


    // Polymorphism. The method calls will call the right methods.
    for(Car* car: cars) {
        std::cout << "STARTING\n";
        car->start();
        std::cout << "DRIVING\n";
        car->drive();
        std::cout << "FUELING\n";
        car->fuel();
        std::cout << "\n";
    }

    std::unique_ptr<Car> cars2[] {
        std::make_unique<ElectricCar>("BMW", "i4", 2020),
        std::make_unique<SportsCar>("Mercedes", "M4", 2022, 350)
    };

    std::cout << "Array of unique pointers\n";

    for(const auto& c: cars2) {
        std::cout << "STARTING\n";
        c->start();
        std::cout << "DRIVING\n";
        c->drive();
        std::cout << "FUELING\n";
        c->fuel();
        std::cout << "\n";
    }
    return 0;
}
