if(DEBUG_IZH_DATA_MANAGER)
    message(STATUS "ZH: DEBUG_IZH_DATA_MANAGER")
    set(CMAKE_BUILD_TYPE "Debug")
else()
    message(STATUS "ZH: RELEASE_IZH_DATA_MANAGER")
    set(CMAKE_BUILD_TYPE "Release")
endif()

add_library(izh_data_manager
    ${IZH_DATA_MANAGER}/DataManager.cpp
)

target_link_libraries(izh_data_manager
    PUBLIC
    izh_toolkit
)

target_include_directories(izh_data_manager
    PUBLIC
    ${IZH_DATA_MANAGER}/advance
    ${IZH_DATA_MANAGER}
)
