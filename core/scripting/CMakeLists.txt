cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()


add_library(wilo_script)
target_link_libraries(wilo_script PUBLIC wilo_lua_lib)
target_link_libraries(wilo_script PRIVATE wilo_dev_core)
target_link_libraries(wilo_script PRIVATE wilo_messaging_core)
target_link_libraries(wilo_script PUBLIC wilo_base)
target_sources(wilo_script
                PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wilo_scriptable.hpp"
                PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wilo_lua_tools.hpp"
                PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wilo_lua_tools.cpp"
                PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/wilo_scriptable.hpp"
                PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/wilo_scriptable.cpp")       

target_include_directories(wilo_script PRIVATE  "${PROJECT_SOURCE_DIR}/wilo/core/base")
target_include_directories(wilo_script PRIVATE "${PROJECT_SOURCE_DIR}/wilo/core/messaging")
target_include_directories(wilo_script PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
    