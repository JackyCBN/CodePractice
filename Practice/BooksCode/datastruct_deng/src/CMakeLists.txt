cmake_minimum_required(VERSION 3.12)
project(src)


#add_executable(main  main.cpp)
MESSAGE( STATUS  "CMAKE_CURRENT_SOURCE_DIR:${CMAKE_CURRENT_SOURCE_DIR}")
    
# files
FILE(GLOB_RECURSE Src
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
	"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/*.cxx")

FILE(GLOB_RECURSE Headers
	"${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

set(Sources ${Src} ${Headers})

#library
add_library(algorithm ${Sources})
target_include_directories(algorithm PUBLIC ${Headers})
add_library(src::algorithm ALIAS algorithm)
#FOLDER
#createSrcGroups(sandbox_source_list)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
PREFIX "Sources"
FILES ${Sources}
)

