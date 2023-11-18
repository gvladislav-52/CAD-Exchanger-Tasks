cmake_minimum_required(VERSION 3.26)
project(3d_curves_hierarchy)

set(CMAKE_CXX_STANDARD 17)

add_executable(3d_curves_hierarchy main.cpp
        Curve_class.cpp
        Curve_class.h
)
