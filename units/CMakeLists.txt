cmake_minimum_required(VERSION 2.6)

project(googleTests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(googleTest googleTest.cpp ../Json.cpp ../Warrior.cpp ../Kalandor.cpp)
target_link_libraries(googleTest ${GTEST_LIBRARIES} pthread)