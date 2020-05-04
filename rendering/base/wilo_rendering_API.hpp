#pragma once
#include "wilo_render_context.hpp"
#include "vulkan_context.hpp"
#include "vulkan_swapchain.hpp"
#include "vulkan_graphics_pipeline.hpp"
#include "vulkan_render_pass.hpp"
#include "vulkan_frame_buffer_array.hpp"
#include "vulkan_render_task_manager.hpp"
#include "wilo_dev_core.hpp"

namespace wilo{
    namespace renderAPI{
   inline wilo::SharedPointer<wilo::RenderingContext> getRenderingContext(wilo::SharedPointer<Window> window){
        return wilo::CreateSharedPointer<VulkanRenderingContext>(window);
    }
   inline wilo::SharedPointer<wilo::Swapchain> getSwapChain(wilo::SharedPointer<wilo::RenderingContext> contextRef){
        return wilo::CreateSharedPointer<VulkanSwapchain>(std::static_pointer_cast<VulkanRenderingContext>(contextRef));
    }
   inline wilo::SharedPointer<wilo::RenderPass> getRenderPass(wilo::SharedPointer<wilo::RenderingContext> contextRef,wilo::SharedPointer<wilo::Swapchain> swapchainRef){
        return wilo::CreateSharedPointer<VulkanRenderPass>(std::static_pointer_cast<VulkanRenderingContext>(contextRef),std::static_pointer_cast<VulkanSwapchain>(swapchainRef));
    }
   inline wilo::SharedPointer<wilo::GraphicsPipeline> getPipeline(wilo::SharedPointer<wilo::RenderingContext> contextRef,wilo::SharedPointer<wilo::Swapchain> swapchainRef){
        return wilo::CreateSharedPointer<VulkanGraphicsPipeline>(std::static_pointer_cast<VulkanRenderingContext>(contextRef),std::static_pointer_cast<VulkanSwapchain>(swapchainRef));
    }
   inline wilo::SharedPointer<wilo::FrameBufferArray> getFrameBufferArray(wilo::SharedPointer<wilo::RenderingContext> contextRef,wilo::SharedPointer<wilo::Swapchain> swapchainRef,wilo::SharedPointer<wilo::RenderPass> renderPassRef){
        return wilo::CreateSharedPointer<VulkanFrameBufferArray>(std::static_pointer_cast<VulkanRenderingContext>(contextRef),std::static_pointer_cast<VulkanSwapchain>(swapchainRef),std::static_pointer_cast<VulkanRenderPass>(renderPassRef));
    }

   inline wilo::SharedPointer<wilo::RenderTaskManager> getTaskManager(wilo::SharedPointer<wilo::RenderingContext> contextRef,wilo::SharedPointer<wilo::Swapchain> swapchainRef,wilo::SharedPointer<wilo::FrameBufferArray> frameBufferArrayRef){
        return wilo::CreateSharedPointer<VulkanRenderTaskManager>(std::static_pointer_cast<VulkanRenderingContext>(contextRef),std::static_pointer_cast<VulkanSwapchain>(swapchainRef),std::static_pointer_cast<VulkanFrameBufferArray>(frameBufferArrayRef));
    }
  } 
}