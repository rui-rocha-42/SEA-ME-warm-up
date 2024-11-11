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
    Car(const Car &); // copy constructor
    virtual ~Car() = default; // destructor
    Car &operator=(const Car &);  // copy/assignment operator
    // Getters/Setters [ENCAPSULATION]
    [[nodiscard]] std::string make() const;

    [[nodiscard]] std::string model() const;

    [[nodiscard]] int year() const;

    void make(std::string);

    void model(std::string);

    void year(int);

    // Virtual function (can be overriden)
    virtual void drive();

    // Pure virtual function (makes class abstract) [POLYMORPHISM]
    // Abstracting the details of how cars start or are fueled [ABSTRACTION]
    virtual void start() const = 0;
    virtual void fuel() = 0;
};

#endif //SEA_ME_WARM_UP_CAR_H
