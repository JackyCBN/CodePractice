cmake_minimum_required(VERSION 3.12)
project(tests)

include(AddGoogleTest)

set(TEST_SOURCES TestMain.cpp firstTest.cpp)
add_executable(MyTests ${TEST_SOURCES})

add_gtest(MyTests)