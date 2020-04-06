#ifndef vkcore_h
#define vkcore_h
#include "vkinit.hpp"
#include "vktypes.hpp"
#include "vkdevice.hpp"
#include <cstdint>
#include<string>
#include<vector>
namespace wilo{
  namespace vk{
     struct coreCreateInfo{
       std::string appName;
       std::vector<const char*> requestedExtensions;
     };

     class Core{
      public:
      Core();
      void initialize(coreCreateInfo);
      void reclaim();
      void registerDevice(Device);
      Device getDevice();
      VkInstance getInstance();
      ~Core();
      private:
      std::vector<const char*> f_getInstanceExtensions(std::vector<const char*>); 
      void f_createInstance(coreCreateInfo);
      void f_setupDebugMessenging();

      bool m_enableValidation;
      VkDebugUtilsMessengerEXT m_debugMessenger;
      VkInstance m_instance;   
      Device m_device; 
     
     
     };
  
  
  }

}
#endif
