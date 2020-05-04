#pragma once
#include "wilo_render_context.hpp"
#include "wilovk.hpp"
namespace wilo{
            class VulkanRenderingContext: public wilo::RenderingContext{
                    //the vulkan rendering context spins up the Vulkan Basic environment. 
                    //the "context" owns the vulkan instance, physical and logical deivce handles, 
                    //the surface, and also the debug messenger

                public:
                //creating a rendering context grants the context, and by extension the renderer
                //shared ownership of the window
                VulkanRenderingContext(wilo::SharedPointer<Window>);
                void initialize(RenderingContext::Info info) override;
                void reclaim() override;
                VkInstance getInstance();
                VkPhysicalDevice getPhysicalDevice();
                VkDevice getDevice();
                VkSurfaceKHR getSurface();
                std::string getShadersPath();
                vk::SwapChainSupportDetails getSwapChainSupportDetails();
                ~VulkanRenderingContext();
                private:
                bool m_enableValidationLayers;
                void setupDebugging();//creates the debug messenger and sets the call back
			    std::vector<const char *> getInstanceExtensions(RenderingContext::Info info);
                std::vector<const char *> getInstanceLayers(RenderingContext::Info info);
                std::vector<const char*> getDeviceExtensions(RenderingContext::Info info);
                void createInstance(RenderingContext::Info info);//creates the vulkan instance, parsing the Application::info 
                void selectPhysicalDevice(RenderingContext::Info info);//based on required ments specified by renderingcontextInfos a physical device is selected
                bool physicalDeviceIsSuitable(VkPhysicalDevice device, RenderingContext::Info info);//returns true if the physical device in the argument meets the requirements. 
                void createLogicalDevice(RenderingContext::Info info);//populates the physical and logical devices (first by validating everything)
                void createSurface();//creates a surface from the window that was passed in 
                wilo::SharedPointer<Window> m_window;
                VkInstance m_instance; 
                VkPhysicalDevice m_physicalDevice;
                VkDevice m_device; 
                VkSurfaceKHR m_surface;
                VkDebugUtilsMessengerEXT m_debugMessenger;
                VkQueue m_graphicsQueue;
                VkQueue m_presentQueue;
                std::string m_shadersPath;
            };

}