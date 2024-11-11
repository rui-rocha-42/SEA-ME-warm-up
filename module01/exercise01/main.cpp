#include "SportsCar.h"

int main()
{
    Car car {"BMW", "i4", 2020};
    car.drive();

    SportsCar car2 {"Mercedes", "M4", 2022, 350};
    car2.drive();

    SportsCar car3 = car2;
    car3.year(2023);
    car3.top_speed(200);
    car3.drive();
    return 0;
}
