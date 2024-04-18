cmake_minimum_required(VERSION 3.5.0)

if(NOT DEFINED KDLH_MASTER_PROJECT)
    set(KDLH_MASTER_PROJECT OFF)
    if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
        set(KDLH_MASTER_PROJECT ON)
    endif()
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(kdlh)

###############################################################################
# common properties
add_library(kdlh_project_options INTERFACE)
add_library(kdlh::project_options ALIAS kdlh_project_options)
target_compile_features(kdlh_project_options INTERFACE cxx_std_17)

add_library(kdlh_project_warnings INTERFACE)
add_library(kdlh::project_warnings ALIAS kdlh_project_warnings)
# todo(Gustav): add extra compiler warnings




###############################################################################
# main lib
add_subdirectory(src)




###############################################################################
# examples
if(KDLH_MASTER_PROJECT)
    add_subdirectory(examples)
endif()




###############################################################################
# tests
if(KDLH_MASTER_PROJECT)
    add_library(kdlh_catch INTERFACE)
    target_include_directories(kdlh_catch
        INTERFACE SYSTEM external/catch
    )
    add_library(kdlh::catch ALIAS kdlh_catch)

    include(CTest)
    add_subdirectory(tests)
endif()
