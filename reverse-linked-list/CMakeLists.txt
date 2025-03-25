cmake_minimum_required(VERSION 3.10)
project(ReverseLinkedList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Werror)

# Основна бібліотека
add_library(LinkedList 
  include/LinkedList.h
  src/LinkedList.cpp
)

# Тести
add_executable(LinkedListTest tests/LinkedListTest.cpp)
target_link_libraries(LinkedListTest 
  PRIVATE 
    LinkedList
    GTest::GTest 
    GTest::Main
)

# Додатково: ціль для прикладу
add_executable(Example example.cpp)
target_link_libraries(Example PRIVATE LinkedList)
