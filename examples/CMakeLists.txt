###############################################################################
# simple kdlh cli
set(main_src cli.cc)
source_group("" FILES ${main_src})
add_executable(kdl ${main_src})
target_link_libraries(kdl
    PUBLIC
        kdlh::kdlh
    PRIVATE
        kdlh::project_options
        kdlh::project_warnings
)



###############################################################################
# example
set(example_src example.cc)
source_group("" FILES ${example_src})
add_executable(example ${example_src})
target_link_libraries(example
    PUBLIC
        kdlh::kdlh
    PRIVATE
        kdlh::project_options
        kdlh::project_warnings
)
