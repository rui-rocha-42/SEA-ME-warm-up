#include <iostream>
#include "Car.h"
int main()
{
    Car car {"BMW", 200};
    std::cout << "Hello, your car " << car.name() << " is currently at " << car.speed() << " km/h\n";

    Car car2 = car;
    car2.speed(150);
    std::cout << "Hello, your cloned car " << car2.name() << " is currently at " << car2.speed() << " km/h\n";

    Car car3 = car2;
    car3.name("Mercedes");
    std::cout << "Hello, your cloned car " << car3.name() << " is currently at " << car3.speed() << " km/h\n";

    car.speed(10);
    std::cout << "Hello, your car " << car.name() << " is currently at " << car.speed() << " km/h\n";

    return 0;
}
