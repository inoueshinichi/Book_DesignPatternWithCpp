# ダウンロードと解凍を行う関数
function(download_and_extract_library NAME EXT URL)
    if(NOT IS_DIRECTORY ${CMAKE_SOURCE_DIR}/third-party/${NAME})
        message(STATUS "Downloading ${NAME}")
        file(DOWNLOAD
            ${URL}
            ${CMAKE_CURRENT_SOURCE_DIR}/${NAME}${EXT}
            SHOW_PROGRESS
            STATUS status
            LOG log)
        list(GET status 0 status_code)
        list(GET status 1 status_string)
        if(NOT status_code EQUAL 0)
            if(UNIX OR APPLE)
                message("Failed to download ${NAME}. Try to download with wget.")
                execute_process(
                    COMMAND wget ${URL} -O ${CMAKE_CURRENT_SOURCE_DIR}/${NAME}${EXT}
                )
            else()
                message(FATAL_ERROR "Failed to download ${NAME}. Please check network connection and proxy settings.
                status_code: ${status_code}
                status_string: ${status_string}
                log: ${log}
                ")
                error() # Place Unknown command to stop cmake process here.
            endif()
        endif()

        execute_process(
            COMMAND ${CMAKE_COMMAND} -E 
            chdir ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_COMMAND} -E tar xf ${NAME}${EXT}
        )
    endif()
endfunction()


###############################################################################
# 以下に追加したいサードパーティ製のライブラリを明記
###############################################################################

# utfcpp(for utf-8)
message(STATUS "Download and Extract library: utfcpp-3.1.2")
download_and_extract_library(utfcpp-3.1.2 .zip https://github.com/nemtrif/utfcpp/archive/v3.1.2.zip)
add_subdirectory(utfcpp-3.1.2)

# nlohmann-json(develop版はc++20対応していると思われる)
message(STATUS "Download and Extract library: nlohmann_json")
download_and_extract_library(json-develop .zip https://github.com/nlohmann/json/archive/develop.zip)
add_subdirectory(json-develop)

