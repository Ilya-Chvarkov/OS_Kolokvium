cmake_minimum_required(VERSION 3.10)
project(RemoveDuplicates LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Werror)

add_library(DuplicatesRemover INTERFACE)
target_include_directories(DuplicatesRemover INTERFACE 
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(DuplicatesRemoverTest tests/DuplicatesRemoverTest.cpp)
target_link_libraries(DuplicatesRemoverTest 
  PRIVATE 
    DuplicatesRemover
    GTest::GTest 
    GTest::Main
)

add_executable(Example example.cpp)
target_link_libraries(Example PRIVATE DuplicatesRemover)
