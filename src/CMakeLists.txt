set(src
    cuddle/cuddle.cc
    cuddle/cuddle.h
)
add_library(cuddle STATIC ${src})
target_link_libraries(cuddle
    PRIVATE
        cuddle::project_options
        cuddle::project_warnings
)
target_include_directories(cuddle
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
add_library(cuddle::cuddle ALIAS cuddle)
