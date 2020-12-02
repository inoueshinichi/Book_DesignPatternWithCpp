cmake_minimum_required(VERSION 3.16.3)

enable_testing()
include("${PROJECT_SOURCE_DIR}/cmake/gtest.cmake")
file(GLOB TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*.cpp")