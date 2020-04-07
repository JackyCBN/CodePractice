cmake_minimum_required(VERSION 3.12)
project(datastruct_cpp)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/../../../Common/CMake)
include(toplevel_config)

# Externally provided content
add_subdirectory(dependencies)


# Main targets built by this project
add_subdirectory(src)

# Things typically only needed if we are the top level project
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    add_subdirectory(tests)
    add_subdirectory(packaging)
endif()