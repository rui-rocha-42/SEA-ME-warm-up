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
        module01/exercise00/car.cpp
        module01/exercise00/car.h)

add_executable(sports_car
        module01/exercise01/main.cpp
        module01/exercise01/car.cpp
        module01/exercise01/car.h
        module01/exercise01/sportscar.cpp
        module01/exercise01/sportscar.h)
