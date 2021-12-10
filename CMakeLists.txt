cmake_minimum_required(VERSION 3.20)
project(Lab2_NavigationCode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab2_NavigationCode
        graphicsStuff.cpp
        main.cpp
        Navigation.cpp
        Navigation.h
        NavigationInterface.h)
