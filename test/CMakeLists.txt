cmake_minimum_required(VERSION 3.16.3)


# GoogleTestプロジェクトを生成
include(${PROJECT_SOURCE_DIR}/cmake/gtest.cmake)

# Testケースの作成
set(TestCaseTarget TestcaseOfGoogle)
add_executable(${TestCaseTarget} 
    ${CMAKE_CURRENT_SOURCE_DIR}/google_test.cpp
)
target_link_libraries(${TestCaseTarget} 
    PRIVATE GTest::GTest
    PRIVATE Threads::Threads
)

# # GoogleTest Include
# message(STATUS "Getting googleTest include directories...")
# ExternalProject_Get_Property(${GTEST_TARGET} INSTALL_DIR)
# set(GTEST_INCLUDE ${INSTALL_DIR}/include)
# message(STATUS "Include Dir of GTest and GMock is ${GTEST_INCLUDE}")


# # GoogleTest Library
# message(STATUS "Getting googleTest library directories...")
# set(GTEST_LIB ${INSTALL_DIR}/lib)
# message(STATUS "Googletest lib dir is ${GTEST_LIB}")

# # Testケースの作成
# set(TestCaseTarget TestcaseOfGoogle)
# add_executable(${TestCaseTarget} 
#     ${CMAKE_CURRENT_SOURCE_DIR}/google_test.cpp
# )
# target_include_directories(${TestCaseTarget} 
#     PRIVATE ${GTEST_INCLUDE}
# )
# target_link_directories(${TestCaseTarget} 
#     PRIVATE ${GTEST_LIB}
# )
# target_link_libraries(${TestCaseTarget}
#     PRIVATE gtest
#     # PRIVATE gmock
#     PRIVATE pthread
# )
# add_dependencies(${TestCaseTarget} GoogleTest)

# file(GLOB TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*.cpp")


