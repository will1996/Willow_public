#include "wilo_renderer.hpp"
namespace wilo{
    Renderer::Renderer(wilo::SharedPointer<wilo::Window> window, wilo::Renderer::Info rendererInfo)
    {
        wilo::RenderingContext::Info context_info;
        p_context = wilo::renderAPI::getRenderingContext(window);
        context_info.appName = "Willo app";
        context_info.appVersion = 0;
        context_info.enableGraphicsDebugging = rendererInfo.enableGraphicsDebugging;
        context_info.enabelGraphicsProfiling = rendererInfo.enableRendererStatistics;
        p_context->initialize(context_info);


        p_swapChain = wilo::renderAPI::getSwapChain(p_context);
        wilo::Swapchain::Info swapChain_info;
        swapChain_info.frameWidthPix = rendererInfo.frameWidth;
        swapChain_info.frameHeightPix = rendererInfo.frameHeight;
        p_swapChain->initialize(swapChain_info);

        p_graphicsPipeline = wilo::renderAPI::getPipeline(p_context,p_swapChain);
        wilo::GraphicsPipeline::Info pipeline_info{};

        VulkanShader fragmentShader(std::static_pointer_cast<VulkanSwapchain>(p_swapChain),
                                        std::static_pointer_cast<VulkanRenderingContext>(p_context));

        fragmentShader.bind("frag.spv",Shader::Type::fragment);

        VulkanShader vertexShader(std::static_pointer_cast<VulkanSwapchain>(p_swapChain),
                                    std::static_pointer_cast<VulkanRenderingContext>(p_context));

        vertexShader.bind("vert.spv",Shader::Type::vertex);
        p_renderPass = wilo::renderAPI::getRenderPass(p_context, p_swapChain);

        p_frameBuffers = wilo::renderAPI::getFrameBufferArray(p_context,p_swapChain,p_renderPass);
        p_frameBuffers->initialize();

        p_graphicsPipeline->bindRenderPass(*p_renderPass);
        p_graphicsPipeline->bindShader(vertexShader);
        p_graphicsPipeline->bindShader(fragmentShader);

        p_graphicsPipeline->initialize(pipeline_info);

        p_taskManager = wilo::renderAPI::getTaskManager(p_context,p_swapChain,p_frameBuffers);
        p_taskManager->SetRenderPass(p_renderPass);
        


        WILO_CORE_INFO("Renderer initialized!");
    }

    void Renderer::draw(){
        p_taskManager->CreateDrawTask(p_graphicsPipeline);
        p_taskManager->SubmitDrawTask();
    }

    void Renderer::handleWindowResize(const wilo::Message& m){
        const wilo::WindowMessage& msg = static_cast<const WindowMessage&>(m);
        p_taskManager->waitOnCurrentTasks();
        Swapchain::Info newInfo;

        newInfo.frameHeightPix = msg.getInfo().height;
        newInfo.frameWidthPix = msg.getInfo().width;
        p_swapChain->reinitialize(newInfo);

        p_frameBuffers->reinitialize();

        p_graphicsPipeline->reinitialize(); 

        p_taskManager->reset();

    }

    Renderer::~Renderer(){
            //let all in-flight tasks finish up before calling quit;
        p_taskManager->waitOnCurrentTasks();

        p_taskManager->reclaim();

        p_frameBuffers->reclaim();
        p_renderPass->reclaim();
        p_graphicsPipeline->reclaim();
        p_swapChain->reclaim();
        p_context->reclaim();
        WILO_CORE_INFO("Renderer reclaimed");
    }
}