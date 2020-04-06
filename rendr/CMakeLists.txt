cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()
  
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

add_library(wilorendr)
target_sources(wilorendr
              PRIVATE renderer.cpp
              PUBLIC renderer.hpp
              PUBLIC wilorendr.hpp)

target_include_directories(wilorendr PUBLIC .)

find_package(Vulkan REQUIRED)
target_include_directories(wilorendr PRIVATE Vulkan::Vulkan)
target_include_directories(wilorendr PRIVATE stb)
target_include_directories(wilorendr PRIVATE tinyobjloader)

target_link_libraries(wilorendr PRIVATE wilovk)
target_link_libraries(wilorendr PRIVATE wilo_dev_core)
target_link_libraries(wilorendr PUBLIC Vulkan::Vulkan)





