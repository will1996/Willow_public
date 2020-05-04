#pragma once
#include"wilo_render_context.hpp"
#include"wilo_swapchain.hpp"
#include"wilo_shader.hpp"
#include "wilo_render_pass.hpp"


namespace wilo{
    class GraphicsPipeline{
        public:
        struct Info{
        };

        GraphicsPipeline(wilo::SharedPointer<wilo::RenderingContext>,
                         wilo::SharedPointer<wilo::Swapchain> )
                           {};

        virtual void initialize(Info settings) = 0;

        virtual void bindRenderPass(wilo::RenderPass&) = 0;
        virtual void bindShader(wilo::Shader&) = 0;
        virtual void reclaim() = 0;
        //rebuild graphics pipeline, re-using all currently bound resources 
        virtual void reinitialize() = 0;

        virtual ~GraphicsPipeline() {};


    };


}