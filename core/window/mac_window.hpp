#pragma once
#include "wilo_dev_core.hpp"
#include "keyboard_message.hpp"
#include "mouse_message.hpp"
#include "window_message.hpp"
#include "window.hpp"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace wilo{
    class MacWindow : public Window{
        public:
         
         MacWindow(Window::Info &info);
         wilo::Window::Info getInfo() const override;
         void initialize()  override;
         void checkIn()     override;
         void reclaim()     override;
         bool shouldClose() override;
         void* getNativeWindow() override;
        
        private:
            void notifyKeyObservers(const wilo::KeyboardMessage& msg);
            void notifyMouseObservers(const wilo::MouseMessage& msg);
            void notifyWindowObservers(const wilo::WindowMessage& msg);
            Window::Info m_info;
            GLFWwindow* m_native_window = nullptr;

    };
}