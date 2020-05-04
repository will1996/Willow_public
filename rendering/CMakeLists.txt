cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()


                
add_subdirectory(base)

add_library(wilo_renderer)
target_link_libraries(wilo_renderer PUBLIC wilo_messaging_core  )
target_link_libraries(wilo_renderer PUBLIC wilo_rendering_base)
target_link_libraries(wilo_renderer PUBLIC wilo_script)
target_link_libraries(wilo_renderer PRIVATE wilo_dev_core)
target_sources(wilo_renderer 
               PUBLIC wilo_renderer.hpp
               PUBLIC wilo_renderer.cpp
               )