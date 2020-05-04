cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()

#definitions for the window library
add_library(wilo_window)           
target_sources(wilo_window
        PUBLIC    "${CMAKE_CURRENT_SOURCE_DIR}/window.hpp"
        PUBLIC    "${CMAKE_CURRENT_SOURCE_DIR}/mac_window.cpp"
        PUBLIC    "${CMAKE_CURRENT_SOURCE_DIR}/mac_window.hpp"
        INTERFACE    "${CMAKE_CURRENT_SOURCE_DIR}/wilo_window.hpp"
            )           

find_package(Vulkan REQUIRED)
target_link_libraries(wilo_window PRIVATE wilo_dev_core)
target_link_libraries(wilo_window PRIVATE wilo_messaging_core)
target_link_libraries(wilo_window PRIVATE Vulkan::Vulkan)
target_link_libraries(wilo_window PUBLIC glfw)

target_include_directories(wilo_window PUBLIC "${PROJECT_SOURCE_DIR}/wilo/external/glfw")
target_include_directories(wilo_window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")