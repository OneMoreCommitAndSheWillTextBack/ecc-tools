add_library(izh_def_flattener
    ${IZH_MODULE}/def_flattener/DefFlattener.cpp
)

target_link_libraries(izh_def_flattener
    PUBLIC
    izh_module
    izh_toolkit
    idm
)

target_include_directories(izh_def_flattener
    PUBLIC
    ${IZH_MODULE}/def_flattener/df_data_manager
    ${IZH_MODULE}/def_flattener
)
