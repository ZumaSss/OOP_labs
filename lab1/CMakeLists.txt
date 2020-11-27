cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(test/googletest-master)
include_directories(test/googletest-master/googletest/include)
include_directories(test/googletest-master/googlemock/include)

add_executable(lab1 main.cpp LinkedList.h test.cpp LinkedList.cpp Iterator.cpp ConstIterator.cpp Node.cpp)
target_link_libraries(lab1 gtest gtest_main)