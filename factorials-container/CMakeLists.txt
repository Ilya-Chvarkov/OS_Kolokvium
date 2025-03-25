cmake_minimum_required(VERSION 3.10)
project(FactorialsContainer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Werror)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_library(Factorials 
  include/Factorials.h
  src/Factorials.cpp
)

add_executable(FactorialsTest tests/FactorialsTest.cpp)
target_link_libraries(FactorialsTest 
  PRIVATE 
    Factorials
    GTest::GTest 
    GTest::Main
)

add_custom_target(run_tests 
  COMMAND ./FactorialsTest
  DEPENDS FactorialsTest
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
