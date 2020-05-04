#pragma once
#include"wilo/rendering/base/wilo_swapchain.hpp"
#include"vulkan_context.hpp"
#include"wilovk.hpp"
namespace wilo{
class VulkanSwapchain: public wilo::Swapchain{
	public:	
		VulkanSwapchain(wilo::SharedPointer<VulkanRenderingContext> pcontext);

		void initialize(wilo::Swapchain::Info) override;
		void reinitialize(wilo::Swapchain::Info) override;
		VkSwapchainKHR get();
		VkExtent2D getSwapSurfaceExtent()const ;
		VkFormat getSwapSurfaceFormat() const;
		const std::vector<VkImageView>& getImageViews()const ;
		void reclaim() override;
private:
	//member variables
		//data used by this class to populate and build itself
	wilo::VulkanSwapchain::Info m_info;
	wilo::SharedPointer<VulkanRenderingContext> p_context;
	vk::SwapChainSupportDetails m_supportDetails;
		
	VkSwapchainKHR m_swapchain;//the real swapchain my dudes; all of this is just a front tbh

		//details about the swapchain images, stored for future use
	VkExtent2D m_swapSurfaceExtent;
	VkSurfaceFormatKHR m_swapSurfaceFormat;
	std::vector<VkImage> m_images;
	std::vector<VkImageView> m_imageViews;

	//member functions
	void createVkSwapchain();
	void getSwapchainImages();
	void createSwapchainImageViews();
		//set the member variables for image format, and extent	
	void chooseSwapSurfaceFormat();
	void 		   chooseSwapChainExtent();
	//helper functions
	VkPresentModeKHR   choosePresentMode();

};

}
