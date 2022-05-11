cmake_minimum_required(VERSION 3.17)
project(Italrecept)

set(CMAKE_CXX_STANDARD 11)

add_executable(Italrecept main.cpp Ingredients.cpp Ingredients.hpp Alcohol.cpp Alcohol.hpp Fruit.cpp Fruit.hpp Recipe.cpp Recipe.hpp)