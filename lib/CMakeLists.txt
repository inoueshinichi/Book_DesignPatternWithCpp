cmake_minimum_required(VERSION 3.16.3)


# # Include Dir
# list(APPEND DESINGN_PATTERN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
# message(STATUS "Include dir: ${DESINGN_PATTERN_INCLUDE_DIR}")

# Source FIles
file(GLOB_RECURSE DESINGN_PATTERN_SRC_FILES "${PROJECT_SOURCE_DIR}/lib/*.cpp")
message(STATUS "Source files: ${DESINGN_PATTERN_SRC_FILES}")

add_library(pattern)
target_sources(pattern PRIVATE ${DESINGN_PATTERN_SRC_FILES})
target_include_directories(pattern PUBLIC ${INCLUDE_DIRECTORIES})