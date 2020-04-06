//render.hpp
#ifndef render_h
#define render_h
#define GLFW_INCLUDE_VULKAN
#include "../vk/vkdevice.hpp"
#include "../vk/vkswapchain.hpp"
#include<memory> 
#include "renderable.hpp"
#include<map>
#include<GLFW/glfw3.h>

namespace wilo{
    namespace rendr{
      class Renderer{
          public:
          Renderer();
          void initialize(vk::Device,VkSurfaceKHR);
          bool addTarget(renderable&);
          bool updateTarget(renderable&);
          void drawFrame();
          void reclaim();
          ~Renderer();
          private:
          VkShaderModule f_createShaderModule(std::vector<char> code);
          std::vector<char> f_readFile(const std::string & filename);
          void f_createRenderPass(vk::Device device);
          void f_createDescriptorSetLayout();
          void f_createGraphicsPipeline(vk::Device);
          void f_createFramebuffers();

          void f_createCommandPool();

          void f_createDepthResources();

          void f_createTextureImage();
          void f_createTextureImageView();
          void f_createTextureSampler();

          void f_createVertexBuffer();
          void f_createIndexBuffer();
          void f_createUniformBuffers();
          void f_createDescriptorPool();
          void f_createDescriptorSets();
          void f_createCommandBuffers();
          void f_createSyncObjects();
          std::map<std::string,renderable&> m_targets;
          vk::Device m_device;
          VkSurfaceKHR m_surface;
          std::unique_ptr<vk::Swapchain> p_swapchain;
          //graphics pipeline members
          VkRenderPass m_renderPass;
          VkDescriptorSetLayout m_descriptorSetLayout;
          VkPipelineLayout m_pipelineLayout;
          VkPipeline m_graphicsPipeline;
          //command pool, should probably be built into VkCore?
          VkCommandPool m_commandPool;

          VkBuffer m_vertexBuffer;
          VkDeviceMemory m_vertexBufferMemory;
          VkBuffer m_indexBuffer;
          VkDeviceMemory m_indexBufferMemory;
          
          std::vector<VkBuffer> m_uniformBuffers;
          std::vector<VkDeviceMemory> m_uniformBuffersMemory;
          VkDescriptorPool m_descriptorPool;
          std::vector<VkDescriptorSet> m_descriptorSets;

          VkImage m_textureImage;
          VkDeviceMemory m_textureImageMemory;
          VkImageView m_textureImageView;
          VkSampler   m_textureSampler;
          
          VkImage m_depthImage;
          VkDeviceMemory m_depthImageMemory;
          VkImageView m_depthImageView;


          std::vector<VkCommandBuffer> m_commandBuffers;
        
          std::vector<VkSemaphore> m_imageAvailableSemaphores;
          std::vector<VkSemaphore> m_renderFinishedSemaphores;
          std::vector<VkFence> m_inFlightFences;
          std::vector<VkFence> m_imagesInFlight;


        
      };
    }
}
#endif
