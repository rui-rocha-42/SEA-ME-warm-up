#ifndef SEA_ME_WARM_UP_CAR_H
#define SEA_ME_WARM_UP_CAR_H

#include <string>

class Car {
    std::string c_name;
    int c_speed;
public:
    Car() = delete;
    Car(std::string  name, int speed); // constructor
    Car(const Car&); // copy constructor
    ~Car() = default; // destructor
    Car& operator = (const Car&);  // copy/assignment operator
    [[nodiscard]] std::string name() const;
    [[nodiscard]] int speed() const;
    void name(std::string);
    void speed(int);
};


#endif //SEA_ME_WARM_UP_CAR_H
