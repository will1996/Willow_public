#pragma once
#include "wilo_observer_system.hpp"
namespace wilo{
    class Window: public Subject{
        public:
        struct Info{
            double m_height = 600;
            double m_width = 800;
            std::string m_title = "Willo App";
            void * m_extraData = nullptr;//here for platform specific info that may need to be added
        };
          virtual ~Window(){};
          virtual Info getInfo() const = 0; 
          virtual void initialize() = 0;
          virtual void checkIn() = 0;
          virtual void reclaim() = 0;
          virtual bool shouldClose() = 0;
    };

}