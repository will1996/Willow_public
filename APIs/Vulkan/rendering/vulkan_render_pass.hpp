#pragma once
#include "wilo_render_pass.hpp"
#include "vulkan_context.hpp"
#include "vulkan_swapchain.hpp"



namespace wilo{
    class VulkanRenderPass : public wilo::RenderPass{
        public:
            VulkanRenderPass (wilo::SharedPointer<VulkanRenderingContext>, wilo::SharedPointer<VulkanSwapchain>);
            void reclaim() override;
            VkRenderPass get();
            ~VulkanRenderPass();
        private:
        wilo::SharedPointer<VulkanRenderingContext> p_context;
        VkRenderPass m_vkRenderPass;

    };




}