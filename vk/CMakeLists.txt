
cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()
    
add_library(wilovk)
target_sources(wilovk
            PUBLIC vkdevice.cpp 
            PUBLIC vkdevice.hpp 
            PUBLIC vkcore.cpp 
            PUBLIC vkcore.hpp 
            PUBLIC vkinit.cpp 
            PUBLIC vkinit.hpp 
            PUBLIC vkutil.cpp 
            PUBLIC vkutil.hpp  
            PUBLIC vktypes.hpp 
            PUBLIC wilovk.hpp
)
target_link_libraries(wilovk PUBLIC Vulkan::Vulkan)
target_link_libraries(wilovk PRIVATE wilo_dev_core)
find_package(Vulkan REQUIRED)

