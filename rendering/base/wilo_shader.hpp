#pragma once
#include "wilo_render_context.hpp"
#include "wilo_swapchain.hpp"
namespace wilo{
    class Shader{
       public:
        enum Type{ fragment, vertex };
        Shader( wilo::SharedPointer<wilo::Swapchain> swapchainRef,
                wilo::SharedPointer<wilo::RenderingContext> contextRef){};

        virtual void bind(std::string shaderFilePath,Type)=0;//read in shader file and create all resources for the graphics pipeline
        virtual void release()=0;//free resources when done

        virtual ~Shader() {};
    };


}