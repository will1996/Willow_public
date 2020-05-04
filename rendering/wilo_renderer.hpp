/*fully abstracted top_level renderer */
#pragma once
#include "base/wilo_render_context.hpp"
#include "base/wilo_swapchain.hpp"
#include "base/wilo_graphics_pipeline.hpp"
#include "base/wilo_rendering_API.hpp"
#include "base/wilo_render_pass.hpp"
#include "base/wilo_frame_buffer_array.hpp"
#include "wilo_observer.hpp"

namespace wilo{
    class Renderer : public Observer{
        public:
            struct Info {
                uint32_t frameWidth;
                uint32_t frameHeight;
                bool enableGraphicsDebugging;
                bool enableRendererStatistics;
            };
        Renderer(wilo::SharedPointer<wilo::Window> p_window,wilo::Renderer::Info info);
        void handleWindowResize( const wilo::Message& msg);
        void draw();
        ~Renderer();
        private:
        wilo::Observer m_messageReciever;
        wilo::SharedPointer<RenderingContext> p_context;
        wilo::SharedPointer<Swapchain> p_swapChain;
        wilo::SharedPointer<RenderPass> p_renderPass;
        wilo::SharedPointer<GraphicsPipeline> p_graphicsPipeline;
        wilo::SharedPointer<FrameBufferArray> p_frameBuffers;
        wilo::SharedPointer<RenderTaskManager> p_taskManager;
        
    };

}