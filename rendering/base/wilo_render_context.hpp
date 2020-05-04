#pragma once
#include"wilo_dev_core.hpp"
#include "wilo_window.hpp"
namespace wilo{
        class RenderingContext{
            public:
                struct Info{
                 std::string appName;
                 uint32_t  appVersion =0;
                 bool enabelGraphicsProfiling;
                 bool enableGraphicsDebugging;
                };
                RenderingContext(wilo::SharedPointer<Window> windowRef){};//enforce that all Rendering Contexts must have a window 
                virtual void initialize(RenderingContext::Info) = 0;
                virtual void reclaim() = 0;
                virtual ~RenderingContext() {};

        };
}