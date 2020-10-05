#pragma once
#include "vulkan_context.hpp"
#include "vulkan_render_buffer.hpp"




namespace wlo{
	class VulkanIndexBuffer{
    public:
        VulkanIndexBuffer();

        void initialize(VulkanRenderingContext*);

        void allocate(size_t nElements) ;

         //populate the array with new data, usually this will put elements into the front of the array,
         //but the optional offset lets you write data to any position 
        void fill(const std::vector<uint32_t>& data,size_t nElements, size_t offset = 0) ;

         //set size to zero, free all memory
        void reclaim() ;

        size_t size() ;//must return the number of elements
        size_t memSizeBytes() ;//must return the memory footprint in bytes
        VkBuffer get();

    private:
        VulkanRenderingContext* p_context;
        VulkanBuffer<uint32_t> m_buffer;
	};

}