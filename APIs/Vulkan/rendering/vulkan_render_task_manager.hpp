#include "wilo_render_task_manager.hpp"

#include "vulkan_context.hpp"
#include "vulkan_swapchain.hpp"
#include "vulkan_frame_buffer_array.hpp"

#include "wilovk.hpp"

namespace wilo{
    class VulkanRenderTaskManager: public wilo::RenderTaskManager{
            public:
             VulkanRenderTaskManager(wilo::SharedPointer<VulkanRenderingContext>,
                                     wilo::SharedPointer<VulkanSwapchain>, 
                                     wilo::SharedPointer<VulkanFrameBufferArray>);
             void reclaim() override;
             void reset() override ;
             void waitOnCurrentTasks() override;
             void SetRenderPass(wilo::SharedPointer<wilo::RenderPass>) override;
             void CreateDrawTask(wilo::SharedPointer<wilo::GraphicsPipeline>)override;
             void SubmitDrawTask()override;

            private:
                const size_t m_numFrameBuffers;
                size_t m_currentFrameIndex;
                wilo::SharedPointer<VulkanRenderingContext> p_context;
                wilo::SharedPointer<VulkanSwapchain> p_swapchain;
                wilo::SharedPointer<VulkanFrameBufferArray> p_frameBufferArray;
                VkRenderPass m_renderPass;
                VkCommandPool m_vkCommandPool;
                std::vector<VkCommandBuffer> m_drawCommandBuffers;

                std::vector<VkSemaphore> imageAvailableSemaphores;
                std::vector<VkSemaphore> renderFinishedSemaphores;
                std::vector<VkFence> commandBufferExecutingFences;
                std::vector<VkFence> imageInUseFences;

                VkQueue graphicsQueue;
                VkQueue presentQueue;

                void createCommandPool();
                void allocateDrawCommandBuffers();
                void createSynchronizationPrimitives();

    };



}