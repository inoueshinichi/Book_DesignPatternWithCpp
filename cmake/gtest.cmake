# Google test settings
cmake_minimum_required(VERSION 3.16.3)

message(STATUS "Download and Build GoogleTest with CMake ExternalProject()")


# Setting GoogleTest Project
set(GTEST_TARGET GoogleTest)
set(GTEST_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/external_project/${GTEST_TARGET})
set(GTEST_INSTALL ${GTEST_PREFIX}/install)

# コンパイル条件
option(GTEST_SHARED_LIB "GoogleTest Shared Lib or Not" ON)

message(STATUS "GoogleTest CMake Target is `${GTEST_TARGET}`")
message(STATUS "CMake ExternalProject Prefix Path is ${GTEST_PREFIX}") # mockがサポートされたのは1.8.0から
message(STATUS "GoogleTest install dir is ${GTEST_INSTALL}")
message(STATUS "GoogleTest shared_lib is ${GTEST_SHARED_LIB}")

# Enable ExternalProject
include(ExternalProject)
ExternalProject_Add(
    # Taget Name
    ${GTEST_TARGET}
    #################### No.0 Common Directory Path ####################
    # 一時ファイルを保存するディレクトリパス
    TMP_DIR ${GTEST_PREFIX}/tmp
    # 各ステップで生成されるタイムスタンプを保存するディレクトリパス
    STAMP_DIR ${GTEST_PREFIX}/stamp
    # 各ステップでのLogファイルを保存するディレクトリパス
    LOG_DIR ${GTEST_PREFIX}/log
    # 解凍前のダウンロード内容(zipなど)を保存するディレクトリパス(※ gitでは, SOURCE_DIRに直接保存される)
    DOWNLOAD_DIR ${GTEST_PREFIX}/archive
    # (解凍後の)ダウンロード内容を保存するディレクトリパス
    SOURCE_DIR ${GTEST_PREFIX}/src
    # ビルド後の成果物を保存するディレクトリパス
    BINARY_DIR ${GTEST_PREFIX}/build
    # ビルド成果物のインストール先のディレクトリパス
    # (※ 実際にはmake installのインストール先に、このプロパティは使われない! make install DESTDIR=~/path/toで指定するかCMakeの-Dオプションで指定)
    INSTALL_DIR ${GTEST_INSTALL} #${GTEST_PREFIX}/install 
    #################### No.1 Download Step ####################
    # 原因不明で前回, git cloneを行っていないのに、すでにgit cloneされていると判断されて、git cloneが実行されない.
    # # Git Repository URL
    # GIT_REPOSITORY https://github.com/google/googletest.git
    # # Git branch-name, tag or commit's hash id
    # GIT_TAG release-1.10.0
    # # Git Remote Name (default: origin)
    # GIT_REMOTE_NAME origin
    # # Git Remote Clone Progress
    # GIT_REMOTE_PROGRESS ON

    # URL Download
    URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
    # Timeout
    TIMEOUT 10 # 10秒
    #################### No.2 Update/Patch Step ####################
    # ダウンロードした内容にパッチを当てるコマンド
    UPDATE_COMMAND ""
    #################### No.3 Configure Step ####################
    # ジェネレータ
    CMAKE_GENERATOR "Unix Makefiles"
    # cmake コマンドに渡す引数
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${GTEST_INSTALL} -DBUILD_SHARED_LIBS=GTEST_SHARED_LIB
    #################### No.4 Build Step ####################
    # ビルドコマンド
    BUILD_COMMAND make
    # Build In Source or Build Out Source
    BUILD_IN_SOURCE OFF
    # Build Always or Not
    BUILD_ALWAYS OFF
    #################### No.5 Install Step ####################
    # インストールコマンド
    INSTALL_COMMAND make install
    #################### No.6 Test Step ####################
    #################### No.7 Output Logging ####################
    LOG_DOWNLOAD ON
    LOG_UPDATE ON
    LOG_PATCH ON
    LOG_CONFIGURE ON
    LOG_BUILD ON
    LOG_INSTALL ON
    LOG_TEST ON
    LOG_MERGED_STDOUTERR ON
    LOG_OUTPUT_ON_FAILURE ON
    #################### No.8 Terminal Access ####################
    #################### No.9 Target ####################
    #################### No.10 Miscellaneous ####################
)

ExternalProject_Get_Property(${GTEST_TARGET} INSTALL_DIR)

# pthread for googletest
find_package(Threads REQUIRED)

# Make GTest::GTest & GTest::GMock
if(GTEST_SHARED_LIB)
  add_library(GTest::GTest SHARED IMPORTED)
  set_target_properties(GTest::GTest PROPERTIES
    IMPORTED_LOCATION ${INSTALL_DIR}/lib/libgtest.so # shared library
    INTERFACE_INCLUDE_DIRECTORIES ${INSTALL_DIR}/include
    INTERFACE_LINK_LIBRARIES Threads::Threads
  )
  add_dependencies(GTest::GTest ${GTEST_TARGET})

  add_library(GTest::GMock SHARED IMPORTED)
  set_target_properties(GTest::GMock PROPERTIES
    IMPORTED_LOCATION ${INSTALL_DIR}/lib/libgmock.so # shared library
    INTERFACE_INCLUDE_DIRECTORIES ${INSTALL_DIR}/include
    INTERFACE_LINK_LIBRARIES Threads::Threads
  )
  add_dependencies(GTest::GMock ${GTEST_TARGET})
else()
add_library(GTest::GTest STATIC IMPORTED)
  set_target_properties(GTest::GTest PROPERTIES
    IMPORTED_IMPLIB ${INSTALL_DIR}/lib/libgtest.a # static library
    INTERFACE_INCLUDE_DIRECTORIES ${INSTALL_DIR}/include
    INTERFACE_LINK_LIBRARIES Threads::Threads
  )
  add_dependencies(GTest::GTest ${GTEST_TARGET})

  add_library(GTest::GMock STATIC IMPORTED)
  set_target_properties(GTest::GMock PROPERTIES
    IMPORTED_IMPLIB ${INSTALL_DIR}/lib/libgmock.a # static library
    INTERFACE_INCLUDE_DIRECTORIES ${INSTALL_DIR}/include
    INTERFACE_LINK_LIBRARIES Threads::Threads
  )
  add_dependencies(GTest::GMock ${GTEST_TARGET})
endif()
