## set path
set(IZH_DATA_MANAGER ${IZH_SOURCE}/data_manager)
set(IZH_MODULE ${IZH_SOURCE}/module)
set(IZH_TOOLKIT ${IZH_SOURCE}/toolkit)

## build
add_subdirectory(${IZH_DATA_MANAGER})
add_subdirectory(${IZH_MODULE})
add_subdirectory(${IZH_TOOLKIT})

add_library(izh_source INTERFACE)

target_link_libraries(izh_source
    INTERFACE
    izh_data_manager
    izh_module
    izh_toolkit
)
