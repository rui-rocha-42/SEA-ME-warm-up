#include "sportscar.h"
int main()
{
    Car car {"BMW", "i4", 2020};
    car.drive();

    SportsCar car2 {"Mercedes", "M4", 2022, 350};
    car2.drive();
    return 0;
}
