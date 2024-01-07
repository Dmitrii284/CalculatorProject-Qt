
cmake_minimum_required(VERSION 3.0)

project(CalculatorProject)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets)

set(SOURCES
        main.cpp
        Calculator.cpp
)

set(HEADERS
        Calculator.h
)

add_executable(calculator ${SOURCES} ${HEADERS})
target_link_libraries(calculator Qt5::Widgets)
