cmake_minimum_required(VERSION 3.16.3)


# Include Dir
list(APPEND DESINGN_PATTERN_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
message(STATUS "Include dir: ${DESINGN_PATTERN_INCLUDE_DIR}")

# Source FIles
file(GLOB_RECURSE DESINGN_PATTERN_SRC_FILES ${PROJECT_SOURCE_DIR}/lib/*.cpp)
message(STATUS "Source files: ${DESINGN_PATTERN_SRC_FILES}")

add_library(pattern)
target_sources(pattern PRIVATE ${DESINGN_PATTERN_SRC_FILES})
target_include_directories(pattern PUBLIC ${DESINGN_PATTERN_INCLUDE_DIR})
target_link_libraries(pattern PUBLIC 
    utf8cpp
    nlohmann_json
    )


###############################################################################
# Qt Configuration
###############################################################################
message(STATUS "========== [START] Qt Configuration ==========")

 # Qt uic, moc, rcc
 set(CMAKE_AUTOUIC ON)
 set(CMAKE_AUTOMOC ON)
 set(CMAKE_AUTORCC ON)


 # Qt Root Dir (環境変数から取得) for find_package cofig mode.
message(STATUS "Qt env path: $ENV{QT5_DIR}")
set(QT_QPA_PLATFORM_PLUGIN_DIR $ENV{QT5_DIR}/plugins/platforms)
list(APPEND CMAKE_PREFIX_PATH $ENV{QT5_DIR})
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
set(Qt5_DIR $ENV{QT5_DIR}/lib/cmake CACHE PATH "Qt5 cmake script path")
message(STATUS "Qt cmake script path: $CACHE{Qt5_DIR}")

find_package(QT NAMES Qt5 CONFIG)

if(QT_FOUND)

    message(STATUS "Found Qt Library.")
    message(STATUS "Qt Version Major : ${QT_VERSION_MAJOR}")
    message(STATUS "Qt Config File Path: ${QT_CONFIG}")

    find_package(Qt${QT_VERSION_MAJOR} CONFIG REQUIRED COMPONENTS
        Core
        Gui
        Widgets    
    )

    # 多言語サポート
    # qt5_create_translation(QT_QM_FILES "${CMAKE_CURRENT_SOURCE_DIR}/mediator_pattern" japanese_JP.ts)


    # UIファイル
    list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/mediator_pattern/ui")
    message(STATUS "Auto Search Path List for AUTOUIC of Qt: ${CMAKE_AUTOUIC_SEARCH_PATHS}")
    message(STATUS "Qt Ui Files: ${QT_UI_FORMS}")

    # RCCファイル
    file(GLOB QT_RCC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/mediator_pattern/rcc/*.qrc")
    message(STATUS "Qt Rcc Files: ${QT_RCC_FILES}")

    # 言語サポート、リソースをターゲットに追加
    target_sources(pattern PRIVATE
        ${QT_QM_FILES}
        ${QT_RCC_FILES}
    )

    # ターゲットにリンク
    target_link_libraries(pattern PRIVATE 
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
    )

    # Qt dllファイルを実行ファイル.exeと同じフォルダにコピーする
    add_custom_command(TARGET pattern POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt${QT_VERSION_MAJOR}::Widgets> $<TARGET_FILE_DIR:pattern>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt${QT_VERSION_MAJOR}::Core> $<TARGET_FILE_DIR:pattern>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt${QT_VERSION_MAJOR}::Gui> $<TARGET_FILE_DIR:pattern>
    )

else()
    message(FATAL_ERROR "Qt ${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH} is not found.")
endif()

message(STATUS "========== [END] Qt Configuration ==========")