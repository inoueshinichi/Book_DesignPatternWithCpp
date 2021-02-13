cmake_minimum_required(VERSION 3.16.3)

project(design_pattern LANGUAGES CXX VERSION 0.1.0)

###############################################################################
# Version
###############################################################################
message(STATUS "========== [START] Version Management ==========")
# CMake Version
message(STATUS "CMake Version: ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}.${CMAKE_TWEAK_VERSION}")

# プロジェクト Version
file(STRINGS ${CMAKE_SOURCE_DIR}/VERSION.txt versions NEWLINE_CONSUME)
string(REGEX REPLACE [[^([A-z0-9.\-_]+).*$]] [[\1]] version ${versions})
string(REGEX REPLACE [[^([0-9]+)\.([0-9]+)\.(.*)$]] [[\1]] version_major ${version})
string(REGEX REPLACE [[^([0-9]+)\.([0-9]+)\.(.*)$]] [[\2]] version_minor ${version})
string(REGEX REPLACE [[^([0-9]+)\.([0-9]+)\.(.*)$]] [[\3]] version_patch ${version})

message(STATUS "========== [END] Version Management ==========")

###############################################################################
# 前処理
###############################################################################
message(STATUS "========== [START] Preprocessing ==========")

# pythonコマンドをCMakeで使えるようにする
set(PYTHON_COMMAND_NAME "python3") # どのインタープリタが選ばれるかはPCの設定次第. もっと詳細設定をコマンドライン引数から与えても良いと思う.
find_program(PYTHON_INTERPRETER ${PYTHON_COMMAND_NAME})
if(NOT EXISTS ${PYTHON_INTERPRETER})
    message(FATAL_ERROR "python [${PYTHON_INTERPRETER}] not found.")
    error() # Place Unknown command to stop cmake process here.
endif()
set(PYTHON_COMMAND "${PYTHON_INTERPRETER}")
message(STATUS "python interpreter: ${PYTHON_INTERPRETER}")

# プログラムで使用するファイルのコピー
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/big1.txt" "${CMAKE_CURRENT_BINARY_DIR}/big1.txt" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/big2.txt" "${CMAKE_CURRENT_BINARY_DIR}/big2.txt" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/big3.txt" "${CMAKE_CURRENT_BINARY_DIR}/big3.txt" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Greeting.html" "${CMAKE_CURRENT_BINARY_DIR}/Greeting.html" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/LinkPage.html" "${CMAKE_CURRENT_BINARY_DIR}/LinkPage.html" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/TablePage.html" "${CMAKE_CURRENT_BINARY_DIR}/TablePage.html" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/welcom.html" "${CMAKE_CURRENT_BINARY_DIR}/welcom.html" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/program.txt" "${CMAKE_CURRENT_BINARY_DIR}/program.txt" COPYONLY)

message(STATUS "========== [END] Preprocessing ==========")

###############################################################################
# 全ターゲットに影響を与えるオプション
###############################################################################
message(STATUS "========== [START] C++ All Target Options ==========")

# Switching Option
option(BUILD_OPENMP "Enable/Disable OpenMP" ON)
option(BUILD_CPP_TEST "Building test" OFF)
option(BUILD_CPP_SHARED_LIBS "Enable/Disable shared libraries" ON)
option(BUILD_CPP_COMPILE_PCH "Enable/Disable compile pre-compile header" OFF)
option(BUILD_CPP_USE_PCH "Enable/Disable use pre-compile header" OFF)

# Global Shared lib flag
if(BUILD_CPP_SHARED_LIBS)
    set(BUILD_CPP_SHARED_LIBS ON)
else()
    set(BUILD_CPP_SHARED_LIBS OFF)
endif()


# C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

if(MSVC) 
    message(STATUS "Compiler: MSVC in Windows")

    # Build Options
    string(REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}") # デフォルトの`/W[0-4]`を削除
    set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /GR /EHsc /W4")
    set(CMAKE_CXX_FLAGS_DEBUG "/Ob0 /Od /MDd /Zi /RTC1") # /MDd or /Od が指定されている場合、#include <windows>内部で_DEBUGマクロが定義される
    set(CMAKE_CXX_FLAGS_RELEASE "/Ob2 /O2 /MD /DNDEBUG") # /DNDEBUGマクロはstatic_assert()で利用する
    set(CMAKE_CXX_FLAGS_MINSIZEREL "/O1 /MD /DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/Od /MDd /Zi /RTC1")

    if(BUILD_OPENMP)
        add_compile_options("$<$<C_COMPILER_ID:MSVC>:/openmp>")
        add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/openmp>")
    endif()

    # ソースコードでUTF-8を使う(MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

    # C++11以降を利用した場合にマクロ変数__cplusplusの値を利用中のC++バージョンに合わせる(つけないとC++98相当の値になる)
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/Zc:__cplusplus>")
    string(APPEND CMAKE_CXX_FLAGS " /Zc:__cplusplus")

    # オブジェクトファイル(*.obj)のサイズ制限を解放
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/bigobj>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/bigobj>")

    # sprintf_s系の邪魔なコンパイラ仕様を回避
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

    # プリコンパイル済みヘッダーの生成と利用
    if(BUILD_CPP_COMPILE_PCH)

    endif()

    if(BUILD_CPP_USE_PCH)

    endif()

elseif(APPLE)
    message(STATUS "Compiler: Clang in macOS")    

    message(FATAL_ERROR "No Implimentation of LLVM with Clang(++) in macOS.")
    
else()
    message(STATUS "Compiler: GCC in Linux")

    # 詳細情報の表示
    # set(CMAKE_VERBOSE_MAKEFILE ON)

    # Build Options(マルチコンフィギュレーション対応)
    set(CMAKE_CXX_FLAGS "-O1")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

    if(BUILD_OPENMP)
        add_compile_options("$<$<C_COMPILER_ID:GCC>:-fopenmp>")
        add_compile_options("$<$<CXX_COMPILER_ID:GCC>:-fopenmp>")
    endif()

    # C++標準に準拠しない拡張機能を無効化
    string(APPEND CMAKE_CXX_FLAGS " --pedantic-errors")

    # https://stackoverflow.com/questions/5088460/flags-to-enable-thorough-and-verbose-g-warnings/9862800#9862800
    string(APPEND CMAKE_CXX_FLAGS " -pedantic")
    string(APPEND CMAKE_CXX_FLAGS " -Wall")
    # string(APPEND CMAKE_CXX_FLAGS " -Wextra")
    # string(APPEND CMAKE_CXX_FLAGS " -Wcast-align")
    # string(APPEND CMAKE_CXX_FLAGS " -Wcast-qual")
    # string(APPEND CMAKE_CXX_FLAGS " -Wctor-dtor-privacy")
    # string(APPEND CMAKE_CXX_FLAGS " -Wdisabled-optimization")
    # string(APPEND CMAKE_CXX_FLAGS " -Wformat=2 ")
    # string(APPEND CMAKE_CXX_FLAGS " -Winit-self")
    # string(APPEND CMAKE_CXX_FLAGS " -Wlogical-op")
    # string(APPEND CMAKE_CXX_FLAGS " -Wmissing-declarations")
    # string(APPEND CMAKE_CXX_FLAGS " -Wmissing-include-dirs")
    # string(APPEND CMAKE_CXX_FLAGS " -Wnoexcept")
    # string(APPEND CMAKE_CXX_FLAGS " -Wold-style-cast")
    # string(APPEND CMAKE_CXX_FLAGS " -Woverloaded-virtual")
    # string(APPEND CMAKE_CXX_FLAGS " -Wredundant-decls")
    # string(APPEND CMAKE_CXX_FLAGS " -Wshadow")
    # string(APPEND CMAKE_CXX_FLAGS " -Wsign-conversion")
    # string(APPEND CMAKE_CXX_FLAGS " -Wsign-promo")
    # string(APPEND CMAKE_CXX_FLAGS " -Wstrict-null-sentinel")
    # string(APPEND CMAKE_CXX_FLAGS " -Wstrict-overflow=5")
    # string(APPEND CMAKE_CXX_FLAGS " -Wswitch-default")
    # string(APPEND CMAKE_CXX_FLAGS " -Wundef")
    # string(APPEND CMAKE_CXX_FLAGS " -Werror")
    # string(APPEND CMAKE_CXX_FLAGS " -Wno-unused")

    # プリコンパイル済みヘッダーの生成と利用
    if(BUILD_CPP_COMPILE_PCH)

    endif()

    if(BUILD_CPP_USE_PCH)

    endif()

endif()

message(STATUS "---------- Compiler Options for Multi Configuration such as XCode, Visual Studio ----------")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "CMAKE_CXX_FLAGS_MINSIZEREL: ${CMAKE_CXX_FLAGS_MINSIZEREL}")
message(STATUS "CMAKE_CXX_FLAGS_RELWITHDEBINFO: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")

###############################################################################
# C++ core
###############################################################################
message(STATUS "========== [START] C++ Build Core ==========")

# Third Party
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party)

# Library
list(APPEND DESIGN_PATTERN_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
message(STATUS "Include dir: ${DESIGN_PATTERN_INCLUDE_DIR}")

message(STATUS "ライブラリを作成します.")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib)



find_package(QT NAMES Qt5 CONFIG)
if(NOT QT_FOUND)
    message(FATAL_ERROR "Qt ${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH} is not found.")
endif()
find_package(Qt${QT_VERSION_MAJOR} CONFIG REQUIRED COMPONENTS
    Core
    Gui
    Widgets    
)
# Windows 拡張ライブラリ
if(WIN32)
    find_package(Qt${QT_VERSION_MAJOR} CONFIG REQUIRED COMPONENTS
        WinExtras
    )
endif()

# App
message(STATUS "実行ファイルを作成します.")
add_executable(design_pattern 
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_include_directories(design_pattern PRIVATE
    ${Qt5Widgets_INCLUDE_DIRS}
)

target_include_directories(design_pattern PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
) 
target_link_directories(design_pattern PRIVATE 
    ${CMAKE_BINARY_DIR}/lib
)
target_link_libraries(design_pattern PRIVATE 
    pattern
)

target_include_directories(design_pattern PRIVATE
    ${CMAKE_BINARY_DIR}/lib
    ${CMAKE_SOURCE_DIR}/include/mediator_pattern
)

 # Qt Root Dir (環境変数から取得) for find_package cofig mode.
 message(STATUS "Qt env path: $ENV{QT5_DIR}")
 set(QT_QPA_PLATFORM_PLUGIN_DIR $ENV{QT5_DIR}/plugins/platforms)
 list(APPEND CMAKE_PREFIX_PATH $ENV{QT5_DIR})
 message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
 set(Qt5_DIR $ENV{QT5_DIR}/lib/cmake CACHE PATH "Qt5 cmake script path")
 message(STATUS "Qt cmake script path: $CACHE{Qt5_DIR}")

 find_package(QT NAMES Qt5 CONFIG)
 find_package(Qt${QT_VERSION_MAJOR} CONFIG REQUIRED COMPONENTS
        Core
        Gui
        Widgets    
    )

target_link_libraries(design_pattern PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
)

# Qt dllファイルを実行ファイル.exeと同じフォルダにコピーする(ビルドイベント機能)
add_custom_command(TARGET design_pattern POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt${QT_VERSION_MAJOR}::Widgets> $<TARGET_FILE_DIR:design_pattern>
COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt${QT_VERSION_MAJOR}::Core> $<TARGET_FILE_DIR:design_pattern>
COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt${QT_VERSION_MAJOR}::Gui> $<TARGET_FILE_DIR:design_pattern>
)

# Windows用のプラットフォームプラグインをコピー
if (MSVC)
add_custom_command(TARGET design_pattern POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt${QT_VERSION_MAJOR}::QWindowsIntegrationPlugin> $<TARGET_FILE_DIR:design_pattern>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt${QT_VERSION_MAJOR}::QWindowsDirect2DIntegrationPlugin> $<TARGET_FILE_DIR:design_pattern>
)
endif()

message(STATUS "========== [END] C++ Build Core ==========")

###############################################################################
# C++ Testing
###############################################################################
message(STATUS "========== [START] Test ==========")

# Google Test
if(BUILD_CPP_TEST)
    add_subdirectory(${PROJECT_SOURCE_DIR}/test)
    # enable_testing()
    # add_subdirectory(${PROJECT_SOURCE_DIR}/third-party)
    
endif()


# include(CTest)
# enable_testing()
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)


message(STATUS "========== [END] Test ==========")
