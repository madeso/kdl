###############################################################################
# simple cuddle cli
set(main_src cli.cc)
source_group("" FILES ${main_src})
add_executable(kdl ${main_src})
target_link_libraries(kdl
    PUBLIC
        cuddle::cuddle
    PRIVATE
        cuddle::project_options
        cuddle::project_warnings
)



###############################################################################
# example
set(example_src example.cc)
source_group("" FILES ${example_src})
add_executable(example ${example_src})
target_link_libraries(example
    PUBLIC
        cuddle::cuddle
    PRIVATE
        cuddle::project_options
        cuddle::project_warnings
)
