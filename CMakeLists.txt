cmake_minimum_required(VERSION 3.0.0)
project(design_pattern VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE INC_FILES "prototype_pattern/*.hpp")
message("Include files: ${INC_FILES}")
file(GLOB_RECURSE SRC_FILES "prototype_pattern/*.cpp")
message("Source files:  ${SRC_FILES}")

add_executable(design_pattern
               main.cpp
               ${INC_FILES}
               ${SRC_FILES}
               )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
