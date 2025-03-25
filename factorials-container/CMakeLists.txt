cmake_minimum_required(VERSION 3.14)  # Минимальная версия CMake
project(FactorialsContainer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Опции компилятора
add_compile_options(-Wall -Wextra -Werror)

# Подключаем GoogleTest через FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1  # Фиксируем стабильную версию
)
FetchContent_MakeAvailable(googletest)

# Основная библиотека
add_library(Factorials
  include/Factorials.h
  src/Factorials.cpp
)

# Тесты
add_executable(FactorialsTest tests/FactorialsTest.cpp)
target_link_libraries(FactorialsTest
  PRIVATE
    Factorials
    gtest_main  # Используем gtest_main вместо GTest::Main
)

# Дополнительная цель для удобства
add_custom_target(run_tests
  COMMAND ./FactorialsTest
  DEPENDS FactorialsTest
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
