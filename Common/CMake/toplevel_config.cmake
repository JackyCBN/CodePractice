# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    message(STATUS "top level config")
	enable_testing()
	
    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
    
    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDE's
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # Docs only available if this is the main app
    find_package(Doxygen)
    if(Doxygen_FOUND)
	    add_subdirectory(docs)
    else()
	    message(STATUS "Doxygen not found, not building docs")
    endif()


    # FetchContent added in CMake 3.11, downloads during the configure step
    include(FetchContent)
    # FetchContent_MakeAvailable was not added until CMake 3.14
    if(${CMAKE_VERSION} VERSION_LESS 3.14)
        include(add_FetchContent_MakeAvailable.cmake)
    endif()
endif()