cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()



set(WILO_ENGINE_SCRIPTS_PATH "\"${PROJECT_SOURCE_DIR}/wilo/core/scripts/\"" )
set(WILO_TESTS_SCRIPTS_PATH "\"${PROJECT_SOURCE_DIR}/tests/scripts/\"" )
set(WILO_ENGINE_VERSION "0")
set(WILO_APIS_PATH "\"${PROJECT_SOURCE_DIR}/wilo/APIs/\"")

configure_file(WiloConfig.h.in "${CMAKE_CURRENT_SOURCE_DIR}/WiloConfig.h")



add_library(wilo_dev_core)
 target_sources(wilo_dev_core 
            PUBLIC logr.hpp
            PRIVATE logr.cpp
            PUBLIC wilo_dev_core.hpp
            )

target_link_libraries(wilo_dev_core PUBLIC spdlog::spdlog)

#target_precompile_headers(wilo_dev_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/base/wilo_dev_core.hpp")

target_include_directories(wilo_dev_core PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(wilo_dev_core INTERFACE "${PROJECT_SOURCE_DIR}")


add_library(wilo_base)

target_sources(wilo_base
    PUBLIC KeyCodes.hpp
    PUBLIC MouseCodes.hpp
    PUBLIC wilo_object_counter.hpp
    PUBLIC wilo_object_counter.cpp
    PUBLIC wilo_engine_element.hpp
    PUBLIC wilo_engine_element.cpp
    PUBLIC KeyCodes.hpp
    PUBLIC wilo_APICodes.hpp
    )

                
target_include_directories(wilo_base PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}") 