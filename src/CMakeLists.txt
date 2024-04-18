set(src
    kdlh/kdlh.cc
    kdlh/kdlh.h
)
add_library(kdlh STATIC ${src})
target_link_libraries(kdlh
    PRIVATE
        kdlh::project_options
        kdlh::project_warnings
)
target_include_directories(kdlh
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
add_library(kdlh::kdlh ALIAS kdlh)
