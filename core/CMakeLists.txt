cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()

add_library(wilo_base)
target_sources(wilo_base 
                 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/base/wilo_engine_manager.hpp"
                 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/base/wilo_engine_manager.cpp"
                 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/base/wilo_engine_element.hpp"
                 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/base/wilo_object_counter.cpp"
                 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/base/wilo_object_counter.hpp"
    )
target_include_directories(wilo_base PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/base/")
    )       

add_library(wilo_script)
target_link_libraries(wilo_script PRIVATE wilo_dev_core)
target_link_libraries(wilo_script PRIVATE wilo_messaging_core)
target_sources(wilo_script
                PUBLIC wilo_scriptable.hpp
                PRIVATE wilo_scriptable.cpp)       

target_include_directories(wilo_script PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/scripting")

add_library(wilo_messaging_core)

target_sources(wilo_messaging_core 
            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/messaging/wilo_message.hpp" 
            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/messaging/keyboard_message.hpp" 
            PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/messaging/keyboard_message.cpp" 
            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/messaging/mouse_message.hpp"
            PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/messaging/mouse_message.cpp"
            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/messaging/window_message.hpp" 
            PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/messaging/window_message.cpp" 
            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/messaging/wilo_observer_system.hpp" 
            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/messaging/wilo_observer.hpp" 
            PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/messaging/wilo_observer.cpp" 
            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/messaging/wilo_subject.hpp" 
            PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/messaging/wilo_subject.cpp" 
            )

target_include_directories(wilo_messaging_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/messaging/")
target_link_libraries(wilo_messaging_core PUBLIC wilo_dev_core)
target_link_libraries(wilo_messaging_core PUBLIC wilo_base)



#definitions for the window library
add_library(wilo_window)           
target_sources(wilo_window
        PUBLIC    "${CMAKE_CURRENT_SOURCE_DIR}/window/window.hpp"
        PUBLIC    "${CMAKE_CURRENT_SOURCE_DIR}/window/mac_window.cpp"
        PUBLIC    "${CMAKE_CURRENT_SOURCE_DIR}/window/mac_window.hpp"
        INTERFACE    "${CMAKE_CURRENT_SOURCE_DIR}/window/wilo_window.hpp"
            )           

target_link_libraries(wilo_window PRIVATE wilo_dev_core)
target_link_libraries(wilo_window PRIVATE wilo_messaging_core)
target_link_libraries(wilo_window PUBLIC glfw)

target_include_directories(wilo_window PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/window/")


add_library(wilo_application)
target_sources(wilo_application
                 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/application/application.hpp"
                 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/application/application.cpp"
                 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/application/wilo_console.hpp"
                 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/application/wilo_console.cpp"
                 )

target_link_libraries(wilo_application PRIVATE wilo_dev_core)
target_link_libraries(wilo_application PRIVATE wilo_window)
target_link_libraries(wilo_application PRIVATE wilo_messaging_core)
target_link_libraries(wilo_application PRIVATE wilo_script)
target_include_directories(wilo_application PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/application/")




    