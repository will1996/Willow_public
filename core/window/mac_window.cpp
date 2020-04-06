#include "mac_window.hpp"
#include "keyboard_message.hpp"
namespace wilo{
    MacWindow::MacWindow(wilo::Window::Info &info){
        m_info.m_extraData = info.m_extraData;
        m_info.m_width = info.m_width;
        m_info.m_height = info.m_height;
        m_info.m_title = info.m_title;
    }
    
    void MacWindow::initialize(){
        bool result = glfwInit();
        WILO_ASSERT(result);
        WILO_CORE_INFO("Creating a window with title {0}, and dimensions ({1},{2})",m_info.m_title,m_info.m_height,m_info.m_width);
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
                KeyboardMessage* msg = new KeyboardMessage(MessageType::KeyPressed,info);
                instance -> notifyKeyObservers(msg);
            }else if(action ==GLFW_REPEAT){
                info.repeat_length = 1;
                KeyboardMessage* msg = new KeyboardMessage(MessageType::KeyHeld,info);
                instance -> notifyKeyObservers(msg);
            }else{//action == GLFW_RELEASE
                info.repeat_length = -1;
                KeyboardMessage* msg = new KeyboardMessage(MessageType::KeyReleased,info);
                instance -> notifyKeyObservers(msg);
            } 
        });

        glfwSetMouseButtonCallback(m_native_window,[](GLFWwindow* window, int button, int action,int mods){
            MacWindow* instance = (MacWindow*) (glfwGetWindowUserPointer(window));
            MouseMessage::Info info;
            info.button = MouseButton(button);  
            info.mod_bundle = KeyModifier(mods);
            if(action == GLFW_PRESS){
                MouseMessage* msg = new MouseMessage(MessageType::MouseButtonPressed,info);
                instance -> notifyMouseObservers(msg);
            }else {//action ==GLFW_RELEASE
                MouseMessage* msg = new MouseMessage(MessageType::MouseButtonReleased,info);
                instance -> notifyMouseObservers(msg);
            }
        });
        glfwSetCursorPosCallback(m_native_window,[](GLFWwindow* window, double xpos, double ypos){
            MacWindow* instance = (MacWindow*)(glfwGetWindowUserPointer(window));
            MouseMessage::Info info;
            info.xPos = xpos;
            info.yPos = ypos;
            MouseMessage* msg = new MouseMessage(MessageType::MouseMoved,info);
            instance ->notifyMouseObservers(msg);
        });
        glfwSetScrollCallback(m_native_window,[](GLFWwindow* window, double xpos, double ypos){
            MacWindow* instance = (MacWindow*)(glfwGetWindowUserPointer(window));
            MouseMessage::Info info;
            info.xScroll_Offset = xpos;
            info.yScroll_Offset = ypos;
            MouseMessage* msg = new MouseMessage(MessageType::MouseScrolled,info);
            instance ->notifyMouseObservers(msg);
        });
    
        glfwSetWindowSizeCallback(m_native_window,[](GLFWwindow* window, int width, int height){
            MacWindow* instance = (MacWindow*)(glfwGetWindowUserPointer(window));
            WindowMessage::Info info;
            info.height = height;
            info.width = width;
            info.title = instance->getInfo().m_title;
            WindowMessage*  msg = new WindowMessage(MessageType::WindowResized,info);
            instance -> notifyWindowObservers(msg);
        });

        glfwSetWindowFocusCallback(m_native_window,[](GLFWwindow* window, int Focused){

            MacWindow* instance = (MacWindow*)(glfwGetWindowUserPointer(window));
            WindowMessage::Info info;
            info.title = instance->getInfo().m_title;
            if(Focused==GLFW_FOCUSED){
            WindowMessage* msg = new WindowMessage(MessageType::WindowResized,info);
            instance -> notifyWindowObservers(msg);
            }

        });

        glfwSetWindowCloseCallback(m_native_window,[](GLFWwindow* window ){

            MacWindow* instance = (MacWindow*)(glfwGetWindowUserPointer(window));
            WindowMessage::Info info;
            info.title = instance->getInfo().m_title;
            WindowMessage* msg = new WindowMessage(MessageType::WindowClose,info);
            instance -> notifyWindowObservers(msg);


        });

        WILO_CORE_INFO("Window initialized!")
    }

    void MacWindow::notifyKeyObservers(KeyboardMessage* m){
            this->notify<KeyboardMessage>(m);
    }
    void MacWindow::notifyMouseObservers(MouseMessage* m){
            this->notify<MouseMessage>(m);
    }
    void MacWindow::notifyWindowObservers(WindowMessage* m){
            this->notify<WindowMessage>(m);
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


}
