cmake_minimum_required(VERSION 3.5)

project(FastSquareRootDoublePrecision LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FastSquareRootDoublePrecision main.cpp)

install(TARGETS FastSquareRootDoublePrecision
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
