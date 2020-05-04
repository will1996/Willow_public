cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()


    
add_library(wilo_messaging_core)
target_link_libraries(wilo_messaging_core PUBLIC wilo_dev_core)
target_link_libraries(wilo_messaging_core PUBLIC wilo_base)
target_sources(wilo_messaging_core 
            PUBLIC  wilo_message.hpp
            PUBLIC  keyboard_message.hpp
            PRIVATE keyboard_message.cpp
            PUBLIC  mouse_message.hpp
            PRIVATE mouse_message.cpp
            PUBLIC  window_message.hpp
            PRIVATE window_message.cpp 
            PUBLIC  wilo_observer_system.hpp 
            PUBLIC  wilo_observer.hpp 
            PRIVATE wilo_observer.cpp 
            PUBLIC  wilo_subject.hpp 
            PRIVATE wilo_subject.cpp
            )

target_include_directories(wilo_messaging_core PRIVATE "${PROJECT_SOURCE_DIR}/wilo/core/base")



target_include_directories(wilo_messaging_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")