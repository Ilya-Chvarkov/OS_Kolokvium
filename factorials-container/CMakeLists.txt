cmake_minimum_required(VERSION 3.10)
project(FactorialsContainer LANGUAGES CXX)

# Налаштування стандарту C++ та опцій компілятора
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Опція для відлагодження (вимкнути для release)
add_compile_options(-Wall -Wextra -Werror)

# Підключення GoogleTest через FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Основна бібліотека
add_library(Factorials 
  include/Factorials.h
  src/Factorials.cpp
)

# Тести
add_executable(FactorialsTest tests/FactorialsTest.cpp)
target_link_libraries(FactorialsTest 
  PRIVATE 
    Factorials
    GTest::GTest 
    GTest::Main
)

# Додаткові цілі для зручності
add_custom_target(run_tests 
  COMMAND ./FactorialsTest
  DEPENDS FactorialsTest
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
