add_executable(test_izh_def_flattener
    ${IZH_TEST}/test_def_flattener/test_def_flattener.cpp
)

target_link_libraries(test_izh_def_flattener
    PRIVATE
    izh_def_flattener
)

add_test(NAME test_izh_def_flattener COMMAND test_izh_def_flattener)
