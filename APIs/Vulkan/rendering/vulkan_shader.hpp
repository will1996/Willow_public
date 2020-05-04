#pragma once
#include"wilo/rendering/base/wilo_shader.hpp"
#include"vulkan_swapchain.hpp"
#include "vulkan_context.hpp"


namespace wilo{
    class VulkanShader : public wilo::Shader{
        public:
        VulkanShader(wilo::SharedPointer<wilo::VulkanSwapchain>,wilo::SharedPointer<wilo::VulkanRenderingContext>);
        void bind(std::string shaderFile, wilo::Shader::Type) override;

        VkShaderModule getModule() const;
        VkPipelineShaderStageCreateInfo getInfo() const;
        wilo::Shader::Type getType() const;
        
        void release() override;
        ~VulkanShader();
        private:
        wilo::SharedPointer<wilo::VulkanSwapchain> p_swapchain;
        wilo::SharedPointer<wilo::VulkanRenderingContext> p_context;

        VkShaderModule m_module;
        VkPipelineShaderStageCreateInfo m_info;
        wilo::Shader::Type m_type;


        //helper functions
        std::vector<char> readFile(std::string path);
         
        
        };

}
