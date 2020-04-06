#include "renderer.hpp"
#include<vector>
#include<iostream>
namespace wilo{
  namespace rendr{
    std::vector<const char*> glfwExtensions(){
      uint32_t glfwExtensionCount;
      const char** glfwExtensions;
      glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
      std::vector<const char*> glfwExtensionVec(glfwExtensions,glfwExtensions+glfwExtensionCount);
      return glfwExtensionVec;
    }
  
  
  }

}
