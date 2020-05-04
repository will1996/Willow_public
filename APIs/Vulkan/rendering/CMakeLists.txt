cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()
    
find_package(Vulkan REQUIRED)

add_library(wilo_Vulkan_rendering)
target_link_libraries(wilo_Vulkan_rendering PRIVATE wilo_dev_core)
target_link_libraries(wilo_Vulkan_rendering PRIVATE wilovk)
target_link_libraries(wilo_Vulkan_rendering PUBLIC wilo_rendering_base)
target_link_libraries(wilo_Vulkan_rendering PUBLIC Vulkan::Vulkan)
target_include_directories(wilo_Vulkan_rendering PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(wilo_Vulkan_rendering PUBLIC "${PROJECT_SOURCE_DIR}/wilo/rendering/base")
target_include_directories(wilo_Vulkan_rendering PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../vk")
target_sources(wilo_Vulkan_rendering
               PUBLIC vulkan_context.hpp
               PUBLIC vulkan_context.cpp
               PUBLIC vulkan_swapchain.hpp
               PUBLIC vulkan_swapchain.cpp
               PUBLIC vulkan_shader.hpp
               PUBLIC vulkan_shader.cpp
               PUBLIC vulkan_render_pass.hpp
               PUBLIC vulkan_render_pass.cpp
               PUBLIC vulkan_graphics_pipeline.hpp
               PUBLIC vulkan_graphics_pipeline.cpp
               PUBLIC vulkan_frame_buffer_array.hpp
               PUBLIC vulkan_frame_buffer_array.cpp
               PUBLIC vulkan_render_task_manager.hpp
               PUBLIC vulkan_render_task_manager.cpp
                ) 