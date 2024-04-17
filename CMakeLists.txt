cmake_minimum_required(VERSION 3.5.0)

if(NOT DEFINED CUDDLE_MASTER_PROJECT)
    set(CUDDLE_MASTER_PROJECT OFF)
    if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
        set(CUDDLE_MASTER_PROJECT ON)
    endif()
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(cuddle)

###############################################################################
# common properties
add_library(cuddle_project_options INTERFACE)
add_library(cuddle::project_options ALIAS cuddle_project_options)
target_compile_features(cuddle_project_options INTERFACE cxx_std_17)

add_library(cuddle_project_warnings INTERFACE)
add_library(cuddle::project_warnings ALIAS cuddle_project_warnings)
# todo(Gustav): add extra compiler warnings




###############################################################################
# main lib
add_subdirectory(src)




###############################################################################
# examples
if(CUDDLE_MASTER_PROJECT)
    add_subdirectory(examples)
endif()




###############################################################################
# tests
if(CUDDLE_MASTER_PROJECT)
    add_library(cuddle_catch INTERFACE)
    target_include_directories(cuddle_catch
        INTERFACE SYSTEM external/catch
    )
    add_library(cuddle::catch ALIAS cuddle_catch)

    include(CTest)
    add_subdirectory(tests)
endif()
