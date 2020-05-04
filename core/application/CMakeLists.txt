cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()




    
add_library(wilo_application)
target_sources(wilo_application
                 PUBLIC application.cpp
                 PUBLIC application.hpp
                 PUBLIC wilo_console.hpp
                 PUBLIC wilo_console.cpp
                 )

target_link_libraries(wilo_application PUBLIC wilo_dev_core)
target_link_libraries(wilo_application PUBLIC wilo_window)
target_link_libraries(wilo_application PUBLIC wilo_messaging_core)
target_link_libraries(wilo_application PUBLIC wilo_script)
target_link_libraries(wilo_application PUBLIC wilo_renderer)

target_include_directories(wilo_application PUBLIC "${PROJECT_SOURCE_DIR}/wilo/core/messaging")
target_include_directories(wilo_application PUBLIC "${PROJECT_SOURCE_DIR}/wilo/core/scripting")
target_include_directories(wilo_application PUBLIC "${PROJECT_SOURCE_DIR}/wilo/core/base")
target_include_directories(wilo_application PUBLIC "${PROJECT_SOURCE_DIR}/wilo/core/window")
target_include_directories(wilo_application PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")