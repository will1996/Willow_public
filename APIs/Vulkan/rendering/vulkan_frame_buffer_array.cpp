#include "vulkan_frame_buffer_array.hpp"

namespace wilo{
    
    VulkanFrameBufferArray::VulkanFrameBufferArray(wilo::SharedPointer<VulkanRenderingContext> contextRef,
                                                   wilo::SharedPointer<VulkanSwapchain> swapchainRef,
                                                   wilo::SharedPointer<VulkanRenderPass> renderPassRef)
                                                   :
                                                   wilo::FrameBufferArray(contextRef,swapchainRef,renderPassRef),
                                                   p_context(contextRef),
                                                   p_swapchain(swapchainRef),
                                                   p_renderPass(renderPassRef)
                                                    { }

    void VulkanFrameBufferArray::initialize(){

        m_vkFrameBuffers.resize(p_swapchain->getImageViews().size());

        for(size_t i =0; i<m_vkFrameBuffers.size(); i++){
            VkImageView attachments[]  = {
                p_swapchain->getImageViews()[i]
            };

            VkFramebufferCreateInfo bufferInfo{};

            bufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;

            bufferInfo.attachmentCount = 1;
            bufferInfo.pAttachments = attachments;

            bufferInfo.renderPass = p_renderPass->get();

            bufferInfo.width = p_swapchain->getSwapSurfaceExtent().width;
            bufferInfo.height = p_swapchain->getSwapSurfaceExtent().height;
            
            bufferInfo.layers = 1;


            VkResult res = vkCreateFramebuffer(p_context->getDevice(),&bufferInfo,nullptr,&m_vkFrameBuffers[i]);

            vk::checkResult(res,"create frame buffer"+std::to_string(i));
        }
    }

    VkFramebuffer VulkanFrameBufferArray :: operator [] (size_t i){
            return m_vkFrameBuffers[i];
    }
    void   VulkanFrameBufferArray::reclaim() {
        for(size_t i=0;i<m_vkFrameBuffers.size();i++)
        vkDestroyFramebuffer(p_context->getDevice(),m_vkFrameBuffers[i],nullptr);
    }
    void  VulkanFrameBufferArray::reinitialize(){
        reclaim();
        initialize();
    }

     size_t VulkanFrameBufferArray::size(){
         return m_vkFrameBuffers.size();
     }
    VulkanFrameBufferArray::~VulkanFrameBufferArray(){}


}