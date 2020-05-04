#pragma once
#include "wilo_render_pass.hpp"
#include "wilo_swapchain.hpp"
#include "wilo_render_context.hpp"
namespace wilo{
    class FrameBufferArray{
        public :
            FrameBufferArray(wilo::SharedPointer<wilo::RenderingContext>,wilo::SharedPointer<wilo::Swapchain> ,wilo::SharedPointer<wilo::RenderPass>){};
            virtual void initialize() = 0;
            virtual void reinitialize() =0;
            virtual ~FrameBufferArray(){};
            virtual void reclaim() = 0;



    };



}