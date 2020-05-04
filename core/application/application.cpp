#include "application.hpp"
#include<iostream>
#include "wilo_dev_core.hpp"
#include "wilo_window.hpp"
#include "wilo_scriptable.hpp"

namespace wilo{
 Application::Application():
 m_main_console(new Console()){

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

     m_main_window = wilo::SharedPointer<Window>(wilo_get_window(window_info));
     m_main_window->initialize();//initialize a platform specific window, making indirected calls
     m_main_window->permit<KeyboardMessage, Application,&Application::recieve>(this) ;//register as an observer with the window, so we recieve events;
     //m_main_window->permit<MouseMessage,Application,&Application::recieve>(this) ;//register as an observer with the window, so we recieve events;
     m_main_window->permit<WindowMessage,Application,&Application::recieve>(this) ;//register as an observer with the window, so we recieve events;

     m_main_console->initialize();
     m_main_console->asSubject()->permit<WindowMessage,Application,&Application::recieve>(this);
     m_main_console->asSubject()->permit<MouseMessage,Application,&Application::recieve>(this);
     m_main_console->asSubject()->permit<KeyboardMessage,Application,&Application::recieve>(this);
     wilo::Renderer::Info rendererInfo;
     rendererInfo.frameHeight = 600;
     rendererInfo.frameHeight = 800;
     rendererInfo.enableGraphicsDebugging = true;
    m_renderer = wilo::CreateUniquePointer<Renderer>(m_main_window,rendererInfo);
    m_main_window->permit<WindowMessage,Renderer,&Renderer::handleWindowResize>(m_renderer.get());

   WILO_CORE_INFO("application initialized!");
 }
 void Application::run(){
     WILO_CORE_INFO("application running!");
     m_main_console->run();//allow the console to run in the background!
     while(!m_shutting_down){
        // m_main_console->checkIn();

        m_main_window->checkIn();//get all these events goin'
        m_renderer->draw();
     }
 }

  void Application::recieve(const wilo::Message& msg){
     WILO_INFO("recieved message {0}",msg.toString());
     if(msg.getType()==MessageType::WindowClose){
         WILO_CORE_INFO("Application shutting down");
         m_shutting_down = true;
         }
     }
 


 void Application::reclaim(){
     m_main_console->reclaim();//destroy console
     Observer::reclaim();//free observer resources
     m_main_window->reclaim();//destroy window
     
     WILO_CORE_INFO("reclamation complete")
 }



}