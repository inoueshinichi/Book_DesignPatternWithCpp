# Google test settings
cmake_minimum_required(VERSION 3.16.3)

# Enable ExternalProject
include(ExternalProject)

# Download
ExternalProject_Add(
    GoogleTest
    URL https://googletest.googlecode.com/files/gtest-1.10.0.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/lib
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
    )

# Include
ExternalProject_Get_Property(GoogleTest source_dir)
include_directories(${source_dir}/include)

# Make Static Lib
ExternalProject_Get_Property(GoogleTest binary_dir)
add_library(gtest STATIC IMPORTED)
set_property(
    TARGET gtest
    PROPERTY IMPORTED_LOCATION ${binary_dir}/libgtest.a
    )
add_library(gtest_main STATIC IMPORTED)

# Link
set_property(
    TARGET gtest_main
    PROPERTY IMPORTED_LOCATION ${binary_dir}/libgtest_main.a
    )


