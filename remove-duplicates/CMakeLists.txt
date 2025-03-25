cmake_minimum_required(VERSION 3.10)
project(DuplicatesRemover)

set(CMAKE_CXX_STANDARD 17)

# Подключаем GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Основная библиотека
add_library(DuplicatesRemover src/DuplicatesRemover.cpp include/DuplicatesRemover.h)

# Тесты
add_executable(DuplicatesRemoverTest tests/DuplicatesRemoverTest.cpp)
target_link_libraries(DuplicatesRemoverTest GTest::GTest GTest::Main DuplicatesRemover)
