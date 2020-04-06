cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()
    
add_subdirectory(external)
add_subdirectory(dev_core)
add_subdirectory(core)
add_subdirectory(vk)
add_subdirectory(rendr)

add_library(wilo INTERFACE)
target_include_directories(wilo INTERFACE .)
target_sources(wilo INTERFACE wilo.hpp)

target_link_libraries(wilo INTERFACE wilo_script)
target_link_libraries(wilo INTERFACE wilo_dev_core)
target_link_libraries(wilo INTERFACE wilo_application)
target_link_libraries(wilo INTERFACE wilo_messaging_core)
target_link_libraries(wilo INTERFACE wilo_window)
target_link_libraries(wilo INTERFACE wilovk)
target_link_libraries(wilo INTERFACE wilorendr)
