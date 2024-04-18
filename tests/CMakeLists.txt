set(KDL_TESTS ${CMAKE_CURRENT_SOURCE_DIR}/../external/kdl/tests/test_cases/)
set(KDL_INPUT ${KDL_TESTS}input/)
set(KDL_EXPECTED ${KDL_TESTS}expected_kdl/)

message(STATUS "tests ${KDL_TESTS}")
message(STATUS "input ${KDL_INPUT}")

file(GLOB input_files
    LIST_DIRECTORIES false
    RELATIVE ${KDL_INPUT}
    CONFIGURE_DEPENDS
    "${KDL_INPUT}*.kdl"
)

add_executable(test_generator generator.cc)

set(generated)
foreach(file_name IN LISTS input_files)
    set(output ${CMAKE_CURRENT_BINARY_DIR}/${file_name}.cc)
    set(input ${KDL_INPUT}${file_name})
    set(expected "${KDL_EXPECTED}${file_name}")
    add_custom_command(
        OUTPUT "${output}"
        DEPENDS ${input} test_generator
        COMMAND test_generator
        ARGS ${file_name} ${input} ${expected} ${output}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating test for ${file_name}"
    )
    list(APPEND generated ${CMAKE_CURRENT_BINARY_DIR}/${file_name}.cc)
endforeach()

set(tests_src main.cc
    ${generated}
)
source_group("" FILES ${tests_src})
add_executable(tests ${tests_src})
target_link_libraries(tests
    PUBLIC
        kdlh::kdlh
    PRIVATE
        kdlh::project_options
        kdlh::project_warnings
        kdlh::catch
)

include(../external/catch/Catch.cmake)
catch_discover_tests(tests)
