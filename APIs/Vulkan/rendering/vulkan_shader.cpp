#include "vulkan_shader.hpp"
#include <fstream>

//this is a comment
namespace wilo{
    VulkanShader::VulkanShader(wilo::SharedPointer<wilo::VulkanSwapchain> swapchainRef,
                               wilo::SharedPointer<wilo::VulkanRenderingContext> contextRef): 
                              wilo::Shader(swapchainRef,contextRef),
                              p_swapchain(swapchainRef),
                              p_context(contextRef)
                               {                }
    VulkanShader::~VulkanShader(){}
    //TODO make shaders compiled from source code, rather than read in as binaries
    void VulkanShader::bind(std::string shaderFileName, wilo::Shader::Type type ){
            m_type = type;
            std::string shaderPath = p_context->getShadersPath() + shaderFileName;
            WILO_CORE_INFO("creating a vulkan shader from the file at:{0} ", shaderPath);
            std::vector<char> byte_code = readFile(shaderPath);

            VkShaderModuleCreateInfo moduleInfo{};
            moduleInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
            moduleInfo.codeSize = byte_code.size();
            moduleInfo.pCode = reinterpret_cast<const uint32_t *> (byte_code.data());//hoo boy

            VkResult res = vkCreateShaderModule(p_context->getDevice(),&moduleInfo,nullptr,&m_module);

            vk::checkResult(res,"create Shader Module");

            VkPipelineShaderStageCreateInfo stageInfo{};

            stageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            
            if(type==wilo::Shader::Type::vertex)
             stageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
            else
             stageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
             stageInfo.pName = "main";
             stageInfo.module = m_module;

            m_info = stageInfo; 
    }


    VkShaderModule VulkanShader::getModule() const {
        return m_module;
    }


    VkPipelineShaderStageCreateInfo VulkanShader::getInfo() const{
        return m_info;
    }

   wilo::Shader::Type VulkanShader::getType() const {
       return m_type;
   }

    void VulkanShader::release(){
           vkDestroyShaderModule(p_context->getDevice(), m_module,nullptr);
    }

    std::vector<char> VulkanShader::readFile(std::string path){
        std::ifstream shader_file (path, std::ios::ate|std::ios::binary);
        if(!shader_file.is_open()){
            WILO_CORE_ERROR("failed to read file from path {0}",path);
            assert(false);
        }
        std::vector<char> byte_code(size_t(shader_file.tellg()));
        shader_file.seekg(0);
        WILO_ASSERT(byte_code.size()!=0 && byte_code.size()%4==0);
        shader_file.read(byte_code.data(),byte_code.size());
        shader_file.close();
        return byte_code;
    }

}