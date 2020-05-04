#pragma once
#include "wilo_render_context.hpp"
#include "wilo_swapchain.hpp"
namespace wilo{
    class RenderPass {
        public:
            RenderPass(wilo::SharedPointer<wilo::RenderingContext> ,wilo::SharedPointer<wilo::Swapchain>){};//Pass in a reference to the swapchain so we can get the proper image formats
            virtual void reclaim() = 0;
            virtual ~RenderPass(){};

    };


}