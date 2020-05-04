#pragma once
#include "wilo_dev_core.hpp"
#include "wilo_observer_system.hpp"
#include "wilo_window.hpp"
#include "wilo_scriptable.hpp"
#include "wilo_console.hpp"
#include "wilo_renderer.hpp"
namespace wilo{
    /*

    
    
    */
    class Application: public Observer{
        public:

            struct Info{
            std::string appName;    
            bool debugging;
            int appVersion;
            const double engineVersion = WILO_ENGINE_VERSION;
            const std::string engineName = "WILLOW";
            Info(std::string name, int version) :appName(name),appVersion(version){}
            };

            Application();
            virtual void recieve(const wilo::Message& msg);
            virtual void initialize();
            void run();
            virtual void reclaim();
            virtual ~Application();
        private:
            wilo::SharedPointer<Window> m_main_window;//the main window for the application 
            wilo::UniquePointer<Console> m_main_console;
            wilo::UniquePointer<Renderer> m_renderer;

            size_t m_id = 0;
            bool m_shutting_down = false;
    };
    
}