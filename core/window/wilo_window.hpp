#pragma once
#include "mac_window.hpp"
namespace wilo{
    //TODO make other platforms available
    inline Window* wilo_get_window(Window::Info& info){
        info.API = wilo::WindowingAPICode::GLFW;
            return new MacWindow(info);
    }
}