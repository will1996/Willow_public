#pragma once
#include "wilo_render_context.hpp"

namespace wilo{
	class Swapchain{
		/*
		Swapchain manages the presentation of images to the screen. 
		It is responsitble for:
		Buffering images up to the screen
		chaning the image on the screen	
		
		As usual, the representations at the top level are light weight, 
		they make efficient calls to their platform specific counterparts
		
		*/
		public:	
			struct Info {
				uint32_t frameWidthPix;
				uint32_t frameHeightPix;
			};
			Swapchain(wilo::SharedPointer<RenderingContext> pcontext){};
			virtual void initialize(Info) = 0;
			virtual void reinitialize(Info) = 0;
			virtual void reclaim() = 0;
			virtual ~Swapchain() {};
	};

}