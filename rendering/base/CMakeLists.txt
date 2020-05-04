cmake_minimum_required( VERSION 3.15...3.16)

if (CMAKE_VERSION VERSION_LESS 3.15)
cmake_policy(VERSION CMAKE_MAJOR_VERSION.CMAKE_MINOR_VERSION)
endif()


add_library(wilo_rendering_base)

target_link_libraries(wilo_rendering_base PUBLIC wilo_dev_core)
target_link_libraries(wilo_rendering_base PUBLIC wilo_application)
target_link_libraries(wilo_rendering_base PUBLIC wilo_window)
target_link_libraries(wilo_rendering_base PUBLIC wilo_APIs)
target_sources(wilo_rendering_base
                PUBLIC wilo_render_context.hpp#graphics context has all symantic information for rendering
                PUBLIC wilo_render_context.cpp
                PUBLIC wilo_swapchain.hpp#swapchain owns framebuffers, manages presentation to the screen
                PUBLIC wilo_swapchain.cpp
                PUBLIC wilo_shader.hpp#encapsulates a shader
                PUBLIC wilo_shader.cpp
                PUBLIC wilo_render_pass.hpp#manages the intermediate images used by the graphics pipeline
                PUBLIC wilo_render_pass.cpp
                PUBLIC wilo_graphics_pipeline.hpp#defines operations for transforming and presenting data
                PUBLIC wilo_graphics_pipeline.cpp
                PUBLIC wilo_rendering_API.hpp
                PUBLIC wilo_frame_buffer_array.hpp
                PUBLIC wilo_frame_buffer_array.cpp
                PUBLIC wilo_render_task_manager.hpp
                PUBLIC wilo_render_task_manager.cpp
                 )
