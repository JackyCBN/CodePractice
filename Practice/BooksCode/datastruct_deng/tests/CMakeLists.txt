cmake_minimum_required(VERSION 3.12)
project(tests)

include(AddGoogleTest)

set(TEST_SOURCES TestMain.cpp bubleSortTest.cpp)
add_executable(MyTests ${TEST_SOURCES})
target_link_libraries(MyTests src)

#target_include_directories(MyTests PRIVATE 
#    ${CMAKE_CURRENT_SOURCE_DIR}/../src)

add_gtest(MyTests)