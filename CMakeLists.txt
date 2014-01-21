cmake_minimum_required (VERSION 2.6)



INCLUDE (CheckIncludeFiles) 
INCLUDE (CheckFunctionExists) 
INCLUDE (CheckSymbolExists) 
INCLUDE (CheckLibraryExists) 
INCLUDE (CheckTypeSize) 

INCLUDE (cmake/distclean.cmake OPTIONAL)
INCLUDE (cmake/libcheck.cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

file(
    GLOB_RECURSE
    cpputils_src
    src/*.cpp
)

file(
    GLOB_RECURSE
    testcpputils_src
    src/*.cpp
    test/src/*.cpp
    test/gtest/gtest-all.cc
)

include_directories("${PROJECT_BINARY_DIR}")
include_directories(include test/)

add_library(
    cpputils
    SHARED
    ${cpputils_src}
)

SET_TARGET_PROPERTIES (
    cpputils
    PROPERTIES
        SOVERSION ${VERSION_MAJOR}
        VERSION ${VERSION_MAJOR}.${VERSION_MINOR}
)

add_executable(
    test
    EXCLUDE_FROM_ALL
    ${testcpputils_src}
)

TARGET_LINK_LIBRARIES(test pthread)

