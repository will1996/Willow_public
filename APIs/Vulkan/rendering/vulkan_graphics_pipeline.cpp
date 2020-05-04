#include "vulkan_graphics_pipeline.hpp"
#include "vulkan_render_pass.hpp"


namespace wilo{

    VulkanGraphicsPipeline::VulkanGraphicsPipeline( wilo::SharedPointer<VulkanRenderingContext> contextRef, 
                                                     wilo::SharedPointer<VulkanSwapchain> swapchainRef ):
                                    wilo::GraphicsPipeline(contextRef,swapchainRef),
                                    p_swapchain(swapchainRef),
                                    p_context(contextRef),
                                    m_fragmentShader( swapchainRef,contextRef),
                                    m_vertexShader(swapchainRef,contextRef)
                                    {
                                    }
    void VulkanGraphicsPipeline::initialize(wilo::GraphicsPipeline::Info settings){
        updateInfo(settings);
        createVkPipeline();
    }

        VulkanGraphicsPipeline::~VulkanGraphicsPipeline(){}

        void VulkanGraphicsPipeline::bindShader(wilo::Shader& shader){
            VulkanShader& vulkanShader = static_cast<VulkanShader&>(shader);

            wilo::Shader::Type shaderType = vulkanShader.getType(); 
            switch(shaderType){
                case  wilo::Shader::Type::vertex :
                    m_vertexShader = vulkanShader;
                    break;

                case wilo::Shader::Type::fragment : 
                    m_fragmentShader = vulkanShader;
                    break;
            }
        } 
        void VulkanGraphicsPipeline::bindRenderPass(wilo::RenderPass& renderPass){
            VulkanRenderPass & vulkanRenderPass = static_cast<VulkanRenderPass&>(renderPass);
            m_vkRenderPass= vulkanRenderPass.get();
        }
        void VulkanGraphicsPipeline::reclaim(){
            vkDestroyShaderModule(p_context->getDevice(),m_fragmentShader.getModule(),nullptr );
            vkDestroyShaderModule(p_context->getDevice(),m_vertexShader.getModule(),nullptr );
            vkDestroyPipelineLayout(p_context->getDevice(),m_vkPipelineLayout,nullptr);
            vkDestroyPipeline(p_context->getDevice(),m_vkPipeline,nullptr);
        }

        void VulkanGraphicsPipeline::reinitialize(){
            //rebuild pipeline, pulling up-to-date information from the swapchain
            vkDestroyPipelineLayout(p_context->getDevice(),m_vkPipelineLayout,nullptr);
            vkDestroyPipeline(p_context->getDevice(),m_vkPipeline,nullptr);
            createVkPipeline();
        } ;

        void VulkanGraphicsPipeline::updateInfo( wilo::GraphicsPipeline::Info info){
            m_info = info;
        }

        void VulkanGraphicsPipeline::setVertexInputState(VkPipelineVertexInputStateCreateInfo& info){
            info.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
            info.vertexBindingDescriptionCount = 0;
            info.pVertexBindingDescriptions = nullptr;
            info.vertexAttributeDescriptionCount = 0;
            info.pVertexAttributeDescriptions = nullptr;
        }
        void VulkanGraphicsPipeline::setVertexAssemblyState(VkPipelineInputAssemblyStateCreateInfo& info){
            info.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
            info.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
            info.primitiveRestartEnable = VK_FALSE;
        }
        void VulkanGraphicsPipeline::setViewportState(VkPipelineViewportStateCreateInfo& info,VkRect2D& scissorState, VkViewport& viewportState){
            info.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;

            viewportState.x = 0.0f;
            viewportState.y = 0.0f;
            viewportState.width = (float)p_swapchain->getSwapSurfaceExtent().width;
            viewportState.height = (float)p_swapchain->getSwapSurfaceExtent().height;
            viewportState.minDepth = 0.0f;
            viewportState.maxDepth = 1.0f;

            scissorState.offset = {0,0};
            scissorState.extent = p_swapchain->getSwapSurfaceExtent();

            info.viewportCount = 1;
            info.scissorCount = 1;
            info.pScissors = &scissorState;
            info.pViewports = &viewportState;

        }
        void VulkanGraphicsPipeline::setRasterizerState(VkPipelineRasterizationStateCreateInfo& info){
                info.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
                info.depthClampEnable = VK_FALSE;
                info.rasterizerDiscardEnable = VK_FALSE;
                info.polygonMode = VK_POLYGON_MODE_FILL;
                info.lineWidth = 1.0f;
                info.cullMode = VK_CULL_MODE_BACK_BIT;
                info.frontFace = VK_FRONT_FACE_CLOCKWISE;
                info.depthBiasEnable = VK_FALSE;
                //TODO implement depth bias settings
        }
        void VulkanGraphicsPipeline::setMultisamplingState(VkPipelineMultisampleStateCreateInfo& info){
            info.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
            info.sampleShadingEnable = VK_FALSE;
            info.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
            //TODO implement more settings

        }
        void VulkanGraphicsPipeline::setColorAttachmentState(VkPipelineColorBlendAttachmentState& colorBlendAttachmentState){

                colorBlendAttachmentState.colorWriteMask = VK_COLOR_COMPONENT_R_BIT|
                                            VK_COLOR_COMPONENT_G_BIT|VK_COLOR_COMPONENT_G_BIT|VK_COLOR_COMPONENT_A_BIT;
                colorBlendAttachmentState.blendEnable = VK_TRUE;

                colorBlendAttachmentState.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
                colorBlendAttachmentState.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
                colorBlendAttachmentState.colorBlendOp  = VK_BLEND_OP_ADD;

                colorBlendAttachmentState.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
                colorBlendAttachmentState.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
                colorBlendAttachmentState.alphaBlendOp = VK_BLEND_OP_ADD;
        }
        void VulkanGraphicsPipeline::setColorBlendingState(VkPipelineColorBlendStateCreateInfo& info){
                info.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;


                info.logicOpEnable = VK_FALSE;
                info.logicOp = VK_LOGIC_OP_COPY;
                
                info.attachmentCount = 1;
                //TODO add settings for blend constants
        }
        void VulkanGraphicsPipeline::setDynamicState(VkPipelineDynamicStateCreateInfo& info){
               //TODO add dynamic state, presently all graphics pipelines are fully immuatble 
        }

        void VulkanGraphicsPipeline::setLayout(VkPipelineLayoutCreateInfo& info){
            info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
            

        }
        void VulkanGraphicsPipeline::createVkPipelineLayout(){
            VkPipelineLayoutCreateInfo layoutInfo{};
            setLayout(layoutInfo);
            VkResult res = vkCreatePipelineLayout(p_context->getDevice(),&layoutInfo, nullptr, &m_vkPipelineLayout);
            vk::checkResult(res,"create graphics pipeline layout");
        }




        void VulkanGraphicsPipeline::createVkPipeline(){
            VkGraphicsPipelineCreateInfo pipelineInfo{};
            pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;

            VkPipelineVertexInputStateCreateInfo inputInfo{};
            setVertexInputState(inputInfo);
            pipelineInfo.pVertexInputState = &inputInfo;

            VkPipelineInputAssemblyStateCreateInfo assemblyInfo{}; 
            setVertexAssemblyState(assemblyInfo);
            pipelineInfo.pInputAssemblyState = &assemblyInfo;

            VkPipelineViewportStateCreateInfo viewportInfo{};
            VkRect2D scissorState;
            VkViewport viewportState;
            setViewportState(viewportInfo,scissorState,viewportState);
            pipelineInfo.pViewportState = &viewportInfo;

            VkPipelineRasterizationStateCreateInfo rasterizationInfo{};
            setRasterizerState(rasterizationInfo);
            pipelineInfo.pRasterizationState = &rasterizationInfo;

            VkPipelineMultisampleStateCreateInfo multisamplingInfo{};
            setMultisamplingState(multisamplingInfo);
            pipelineInfo.pMultisampleState = &multisamplingInfo;



            VkPipelineColorBlendStateCreateInfo colorBlendInfo{};
            setColorBlendingState(colorBlendInfo);
            pipelineInfo.pColorBlendState = &colorBlendInfo;

            VkPipelineColorBlendAttachmentState colorBlendAttachmentState{};
            setColorAttachmentState(colorBlendAttachmentState);
            colorBlendInfo.pAttachments = &colorBlendAttachmentState;

            VkPipelineShaderStageCreateInfo shaderInfo[] = {m_vertexShader.getInfo(),m_fragmentShader.getInfo()};
            pipelineInfo.stageCount =  2;
            pipelineInfo.pStages =shaderInfo;


            //dynamic state is nullptr, meaning there is no dymnamic state!
            pipelineInfo.pDynamicState = nullptr; 

            pipelineInfo.renderPass = m_vkRenderPass;
            pipelineInfo.subpass = 0;

            createVkPipelineLayout();
            pipelineInfo.layout = m_vkPipelineLayout;

            pipelineInfo.basePipelineHandle = VK_NULL_HANDLE;
            pipelineInfo.basePipelineIndex = -1;

            VkResult res = vkCreateGraphicsPipelines(p_context->getDevice(),VK_NULL_HANDLE,1, &pipelineInfo,nullptr, &m_vkPipeline);
            vk::checkResult(res,"create graphics pipeline");
            
 
        }

        VkPipeline VulkanGraphicsPipeline::get(){
            return m_vkPipeline;
        }




}

