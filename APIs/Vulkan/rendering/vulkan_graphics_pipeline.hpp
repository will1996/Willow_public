#pragma once
#include"vulkan_context.hpp"
#include "vulkan_swapchain.hpp"
#include "vulkan_shader.hpp"
#include "wilo_graphics_pipeline.hpp"
#include "wilovk.hpp"


namespace wilo{
    class VulkanGraphicsPipeline: public wilo::GraphicsPipeline {
        public:
        VulkanGraphicsPipeline(wilo::SharedPointer<VulkanRenderingContext>, wilo::SharedPointer<VulkanSwapchain>);
        void bindShader(wilo::Shader& shader) override;
        void bindRenderPass(wilo::RenderPass& renderPass) override;
        void initialize(wilo::GraphicsPipeline::Info settings) override;
        VkPipeline get();
        
        void reinitialize() override;

        void reclaim() override;
        ~VulkanGraphicsPipeline();
        private:
        wilo::GraphicsPipeline::Info m_info;
        wilo::SharedPointer<VulkanRenderingContext> p_context;
        wilo::SharedPointer<VulkanSwapchain> p_swapchain;
        void updateInfo( wilo::GraphicsPipeline::Info);

        void setVertexInputState(VkPipelineVertexInputStateCreateInfo&);
        void setVertexAssemblyState(VkPipelineInputAssemblyStateCreateInfo&);
        void setViewportState(VkPipelineViewportStateCreateInfo&,VkRect2D& scissorMemory,VkViewport& viewportMemory);
        void setRasterizerState(VkPipelineRasterizationStateCreateInfo&);
        void setMultisamplingState(VkPipelineMultisampleStateCreateInfo&);
        void setColorAttachmentState(VkPipelineColorBlendAttachmentState&);
        void setColorBlendingState(VkPipelineColorBlendStateCreateInfo&);
        void setDynamicState(VkPipelineDynamicStateCreateInfo&);
        void setLayout(VkPipelineLayoutCreateInfo&);
        void createVkPipelineLayout();
        void createVkPipeline();



        VulkanShader m_vertexShader;
        VulkanShader m_fragmentShader;
        
        VkPipelineLayout m_vkPipelineLayout;
        VkPipeline m_vkPipeline;
        VkRenderPass m_vkRenderPass;
    };


}


