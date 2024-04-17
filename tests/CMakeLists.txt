set(tests_src main.cc
    # todo(Gustav): transform generator against exisitng kdl tests
    generator.cc
)
source_group("" FILES ${tests_src})
add_executable(tests ${tests_src})
target_link_libraries(tests
    PUBLIC
        cuddle::cuddle
    PRIVATE
        cuddle::project_options
        cuddle::project_warnings
        cuddle::catch
)

include(../external/catch/Catch.cmake)
catch_discover_tests(tests)
