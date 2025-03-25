cmake_minimum_required(VERSION 3.10)
project(FactorialsContainer)

set(CMAKE_CXX_STANDARD 17)

# Подключаем GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Основная библиотека
add_library(Factorials src/Factorials.cpp include/Factorials.h)

# Тесты
add_executable(FactorialsTest tests/FactorialsTest.cpp)
target_link_libraries(FactorialsTest GTest::GTest GTest::Main Factorials)
