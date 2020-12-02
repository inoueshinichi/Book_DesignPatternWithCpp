cmake_minimum_required(VERSION 3.16.3)
project(design_pattern VERSION 0.1.0)

# CMake Version
message("CMake Version: ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}.${CMAKE_TWEAK_VERSION}")
# 詳細情報の表示
# set(CMAKE_VERBOSE_MAKEFILE ON)

# Switching
option(BUILD_CPP_TEST "Building test" OFF)
set(BUILD_SHARED_LIBS ON)

###############################################################################
# 全ターゲットに影響を与えるオプション
###############################################################################
# ソースコードでUTF-8を使う(GCC++)
add_compile_options($<$<CXX_COMPILER_ID:GCC>:/utf-8>)

# C++11以降を利用した場合にマクロ変数__cplusplusの値を利用中のC++バージョンに合わせる(つけないとC++98相当の値になる)
add_compile_options($<$<CXX_COMPILER_ID:UNIX>:/Zc:__cplusplus>)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

# Build Options(マルチコンフィギュレーション:visual studio対応)
set(CMAKE_CXX_FLAGS "-O1 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -DNDEBUG")

###############################################################################
# C++ core
###############################################################################
list(APPEND DESIGN_PATTERN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(${DESIGN_PATTERN_INCLUDE_DIR})
message(STATUS "Include dir: ${DESIGN_PATTERN_INCLUDE_DIR}")

message(STATUS "ライブラリを作成します.")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib)

message(STATUS "実行ファイルを作成します.")
add_executable(design_pattern main.cpp)
target_link_libraries(design_pattern PRIVATE pattern)
# target_include_directories(design_pattern PUBLIC ${PROJECT_SOURCE_DIR}/include)   

###############################################################################
# C++ Testing
###############################################################################

# # Google Test
# if(BUILD_CPP_TEST)
#     add_subdirectory(${PROJECT_SOURCE_DIR}/third-party)
#     add_subdirectory(${PROJECT_SOURCE_DIR}/test)
# endif()


# include(CTest)
# enable_testing()
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
