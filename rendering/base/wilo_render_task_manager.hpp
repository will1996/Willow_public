#include "wilo_render_context.hpp"
#include "wilo_graphics_pipeline.hpp"
#include "wilo_swapchain.hpp"
#include "wilo_render_pass.hpp"
#include "wilo_frame_buffer_array.hpp"


namespace wilo{
    class RenderTaskManager{
        public:
        RenderTaskManager(
            wilo::SharedPointer<wilo::RenderingContext> p_context,
            wilo::SharedPointer<wilo::Swapchain> p_swapchain,
            wilo::SharedPointer<wilo::FrameBufferArray> p_frameBufferArray
        ){};
        virtual void reclaim() = 0;


        virtual void waitOnCurrentTasks() = 0;
        //reset internal logic for sycnhonziing draw tasks
        virtual void reset() = 0;

        virtual void SetRenderPass(wilo::SharedPointer<wilo::RenderPass>) = 0;
        //creating a draw task pushes it into a draw task buffer, the draw task buffer has
        //as many elements as there are frame buffers, and will overwrite them in the order they are submitted. 
        virtual void CreateDrawTask(wilo::SharedPointer<wilo::GraphicsPipeline>) = 0;
        virtual void SubmitDrawTask() = 0;

        virtual ~RenderTaskManager(){};
    };


}