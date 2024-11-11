cmake_minimum_required(VERSION 3.27)
project(SEA_ME_warm_up)

set(CMAKE_CXX_STANDARD 23)

add_executable(convert
        module00/exercise02/main.cpp)

add_executable(phonebook
        module00/exercise03/contact.cpp
        module00/exercise03/phonebook.cpp
        module00/exercise03/main.cpp)

add_executable(canonical
        module01/exercise00/main.cpp
        module01/exercise00/Car.cpp
        module01/exercise00/Car.h)

add_executable(sports_car
        module01/exercise01/main.cpp
        module01/exercise01/Car.cpp
        module01/exercise01/Car.h
        module01/exercise01/SportsCar.cpp
        module01/exercise01/SportsCar.h)

add_executable(sports_car_expanded
        module01/exercise02/main.cpp
        module01/exercise02/Car.cpp
        module01/exercise02/Car.h
        module01/exercise02/SportsCar.cpp
        module01/exercise02/SportsCar.h
        module01/exercise02/ElectricCar.cpp
        module01/exercise02/ElectricCar.h)
