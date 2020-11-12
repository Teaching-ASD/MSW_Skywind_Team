cmake_minimum_required(VERSION 2.6)

project(googleTests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(googleTests googleTests.cpp ../Hero.cpp ../Monster.cpp ../JSON.cpp)
target_link_libraries(googleTests ${GTEST_LIBRARIES} pthread)