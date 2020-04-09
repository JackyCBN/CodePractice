cmake_minimum_required(VERSION 3.12)
project(tests)

include(AddGoogleTest)

set(TEST_SOURCES TestMain.cpp bubleSortTest.cpp ../src/sort/bubbleSort.cpp)
add_executable(MyTests ${TEST_SOURCES})
target_include_directories(MyTests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../src)

add_gtest(MyTests)