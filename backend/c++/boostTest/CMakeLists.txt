cmake_minimum_required(VERSION 3.15)
project(boostTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(boostTest main.cpp)

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost REQUIRED COMPONENTS regex)

include_directories(${Boost_INCLUDE_DIR})
# Note: a target should be already defined using 'add_executable' or 'add_library'
target_link_libraries(boostTest ${Boost_LIBRARIES})