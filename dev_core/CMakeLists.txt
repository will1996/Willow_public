cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()


add_library(wilo_dev_core)

target_sources(wilo_dev_core 
            PUBLIC logr.hpp 
            PUBLIC logr.cpp 
            PUBLIC MouseCodes.hpp
            PUBLIC KeyCodes.hpp
            PUBLIC wilo_dev_core.hpp
            #lua_tools
            PRIVATE wilo_lua_tools.cpp
            PUBLIC wilo_lua_tools.hpp
            )



target_link_libraries(wilo_dev_core PUBLIC spdlog::spdlog)

target_link_libraries(wilo_dev_core PUBLIC wilo_lua_lib)
#target_precompile_headers(wilo_dev_core PUBLIC wilo_dev_core.hpp)

target_include_directories(wilo_dev_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

                
