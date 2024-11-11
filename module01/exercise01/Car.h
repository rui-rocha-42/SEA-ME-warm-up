#ifndef SEA_ME_WARM_UP_CAR_H
#define SEA_ME_WARM_UP_CAR_H

#include <string>

class Car {
protected:
    std::string c_make;
    std::string c_model;
    int c_year;
public:
    Car() = delete;
    Car(std::string, std::string, int); // constructor
    Car(const Car&); // copy constructor
    ~Car() = default; // destructor
    Car& operator = (const Car&);  // copy/assignment operator
    [[nodiscard]] std::string make() const;
    [[nodiscard]] std::string model() const;
    [[nodiscard]] int year() const;
    void make(std::string);
    void model(std::string);
    void year(int);
    virtual void drive();
};


#endif //SEA_ME_WARM_UP_CAR_H
