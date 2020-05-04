#include "mac_window.hpp"
#include "keyboard_message.hpp"
namespace wilo{
    MacWindow::MacWindow(wilo::Window::Info &info){
        m_info.m_extraData = info.m_extraData;
        m_info.m_width = info.m_width;
        m_info.m_height = info.m_height;
        m_info.m_title = info.m_title;
        m_info.API = info.API;
    }
    
    void MacWindow::initialize(){
        bool result = glfwInit();
        WILO_ASSERT(result);
        WILO_CORE_INFO("Creating a window with title {0}, and dimensions ({1},{2})",m_info.m_title,m_info.m_height,m_info.m_width);


        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);//this is required for using Vulkan with this window

        m_native_window = glfwCreateWindow(m_info.m_width
                        ,m_info.m_height
                        ,m_info.m_title.c_str()
                        ,nullptr//we don't specify a monitor (yet)
                        ,nullptr//we don't want to use share funcitonality
                        );
        WILO_ASSERT(m_native_window!=nullptr);
            //give GLFW a reference to this macWindow instance such that our
                //glfw callbacks can access "this"
        glfwSetWindowUserPointer(m_native_window,this);

        glfwSetErrorCallback([](int error,const char* error_description){
            WILO_CORE_ERROR(error_description);
        });

        glfwSetKeyCallback(m_native_window,[](GLFWwindow* window, int key, int scancode, int action,int mods){
            MacWindow* instance  =  (MacWindow*) (glfwGetWindowUserPointer(window));
            KeyboardMessage::Info info; 
            info.button = KeyCode(key);
            info.mod_bundle = KeyModifier(mods);
            if(action==GLFW_PRESS){
                info.repeat_length = 0;
                instance -> notifyKeyObservers( wilo::KeyboardMessage(MessageType::KeyPressed,info));
            }else if(action ==GLFW_REPEAT){
                info.repeat_length = 1;
                instance -> notifyKeyObservers( wilo::KeyboardMessage(MessageType::KeyHeld,info));
            }else{//action == GLFW_RELEASE
                info.repeat_length = -1;
                instance -> notifyKeyObservers( wilo::KeyboardMessage(MessageType::KeyReleased,info));
            } 
        });

        glfwSetMouseButtonCallback(m_native_window,[](GLFWwindow* window, int button, int action,int mods){
            MacWindow* instance = (MacWindow*) (glfwGetWindowUserPointer(window));
            MouseMessage::Info info;
            info.button = MouseButton(button);  
            info.mod_bundle = KeyModifier(mods);
            if(action == GLFW_PRESS){
                instance -> notifyMouseObservers( wilo::MouseMessage(MessageType::MouseButtonPressed,info));
            }else {//action ==GLFW_RELEASE
                instance -> notifyMouseObservers( wilo::MouseMessage(MessageType::MouseButtonReleased,info));
            }
        });
        glfwSetCursorPosCallback(m_native_window,[](GLFWwindow* window, double xpos, double ypos){
            MacWindow* instance = (MacWindow*)(glfwGetWindowUserPointer(window));
            MouseMessage::Info info;
            info.xPos = xpos;
            info.yPos = ypos;
            instance ->notifyMouseObservers( wilo::MouseMessage(MessageType::MouseMoved,info));
        });
        glfwSetScrollCallback(m_native_window,[](GLFWwindow* window, double xpos, double ypos){
            MacWindow* instance = (MacWindow*)(glfwGetWindowUserPointer(window));
            MouseMessage::Info info;
            info.xScroll_Offset = xpos;
            info.yScroll_Offset = ypos;
            instance ->notifyMouseObservers( wilo::MouseMessage(MessageType::MouseScrolled,info));
        });
    
        glfwSetWindowSizeCallback(m_native_window,[](GLFWwindow* window, int width, int height){
            MacWindow* instance = (MacWindow*)(glfwGetWindowUserPointer(window));
            WindowMessage::Info info;
            info.height = height;
            info.width = width;
            info.title = instance->getInfo().m_title;
            instance -> notifyWindowObservers( WindowMessage(MessageType::WindowResized,info));
        });

        glfwSetWindowFocusCallback(m_native_window,[](GLFWwindow* window, int Focused){

            MacWindow* instance = (MacWindow*)(glfwGetWindowUserPointer(window));
            WindowMessage::Info info;
            info.title = instance->getInfo().m_title;
            if(Focused==GLFW_FOCUSED){
            instance -> notifyWindowObservers( WindowMessage(MessageType::WindowResized,info));
            }

        });

        glfwSetWindowCloseCallback(m_native_window,[](GLFWwindow* window ){

            MacWindow* instance = (MacWindow*)(glfwGetWindowUserPointer(window));
            WindowMessage::Info info;
            info.title = instance->getInfo().m_title;
            instance -> notifyWindowObservers( WindowMessage(MessageType::WindowClose,info));


        });

        WILO_CORE_INFO("Window initialized!")
    }

    void MacWindow::notifyKeyObservers(const wilo::KeyboardMessage& msg){
            this->notify<KeyboardMessage>(msg);
    }
    void MacWindow::notifyMouseObservers(const wilo::MouseMessage& msg){
            this->notify<MouseMessage>(msg);
    }
    void MacWindow::notifyWindowObservers(const wilo::WindowMessage& msg){
            this->notify<WindowMessage>(msg);
    }

    Window::Info MacWindow::getInfo() const{
        return m_info;
    }
    void MacWindow::checkIn(){
        glfwPollEvents(); //let glfw trigger all callbacks
    };
    void MacWindow::reclaim(){
        glfwTerminate();
    };

    bool MacWindow::shouldClose(){
        return glfwWindowShouldClose(m_native_window);
    }

    void* MacWindow::getNativeWindow()
    {
        std::cout << "getting native Window!" << std::endl;
        return m_native_window;
    }


}
