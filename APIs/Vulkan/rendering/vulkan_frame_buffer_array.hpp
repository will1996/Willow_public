#pragma once
#include "wilo_frame_buffer_array.hpp"
#include "vulkan_swapchain.hpp"
#include "vulkan_render_pass.hpp"
#include "vulkan_context.hpp"

#include "wilovk.hpp"

namespace wilo{
        class VulkanFrameBufferArray :  public wilo::FrameBufferArray{
            public:
                VulkanFrameBufferArray(wilo::SharedPointer<VulkanRenderingContext>, 
                                           wilo::SharedPointer<VulkanSwapchain>, wilo::SharedPointer<VulkanRenderPass>);
                void initialize() override;
                void reclaim() override;
                void reinitialize()override;
                size_t size();
                VkFramebuffer operator [] (size_t i);
                ~VulkanFrameBufferArray();
            private:
                std::vector<VkFramebuffer> m_vkFrameBuffers;
                wilo::SharedPointer<VulkanRenderingContext> p_context;
                wilo::SharedPointer<VulkanSwapchain> p_swapchain;
                wilo::SharedPointer<VulkanRenderPass> p_renderPass;
                  

        };



}