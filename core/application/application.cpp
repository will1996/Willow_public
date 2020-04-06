#include "application.hpp"
#include<iostream>
#include "wilo_dev_core.hpp"
#include "wilo_window.hpp"
#include "wilo_scriptable.hpp"

namespace wilo{
 Application::Application(){
     //do nothing, as is our way.
 }
 Application::~Application(){
     //do nothing, as is our way. 
 }
 void Application::initialize(){
     wilo::logr::initalize();
     wilo::Window::Info window_info;
     window_info.m_height = 600;
     window_info.m_width = 800;
     window_info.m_title = "Astral!";
     m_main_window = wilo_get_window(window_info);
     m_main_window->initialize();//initialize a platform specific window, making indirected calls
     m_main_window->permit<KeyboardMessage, Application,&Application::recieve>(this) ;//register as an observer with the window, so we recieve events;
     //m_main_window->permit<MouseMessage,Application,&Application::recieve>(this) ;//register as an observer with the window, so we recieve events;
     m_main_window->permit<WindowMessage,Application,&Application::recieve>(this) ;//register as an observer with the window, so we recieve events;

     m_main_console = new Console();
     m_main_console->initialize();
     m_main_console->permit<WindowMessage,Application,&Application::recieve>(this);
     std::string test_command = "print('hello from Lua!')";
    //  R"(
    //     print "hello from lua"
    //     --print 'now attempting to quit using Lua'
    //     --wilo_Console:quit 
    // )";
     m_main_console->evaluate(test_command);

   WILO_CORE_INFO("application initialized!");
 }
 void Application::run(){
     WILO_CORE_INFO("application running!");
     while(!m_shutting_down){
        m_main_window->checkIn();//get all these events goin'
     }
 }

  void Application::recieve(Message* msg){
     WILO_INFO("recieved message {0}",msg->toString());
     if(msg->getType()==MessageType::WindowClose){
         WILO_CORE_INFO("Application shutting down");
         m_shutting_down = true;
     }else if(msg->getType()==MessageType::KeyPressed){
         KeyboardMessage* msg_cpy = static_cast<KeyboardMessage*> (msg);
         KeyboardMessage::Info keyInfo = msg_cpy->getInfo();
         if(keyInfo.hasModifier(KeyModifier::SUPER) and keyInfo.button==KeyCode::S)
            m_main_console->checkIn();
         }
     }
 


 void Application::reclaim(){
     Observer::reclaim();//free observer resources
     m_main_window->reclaim();//destroy window
     WILO_CORE_INFO("reclamation complete")
 }



}