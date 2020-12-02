cmake_minimum_required(VERSION 3.16.3)

download_and_extract_library(googletest-release-1.10.0 .zip https://github.com/google/googletest/archive/release-1.10.0.zip)
add_subdirectory(googletest-release-1.10.0)