#pragma once
#include "wilo_dev_core.hpp"
#include "wilo_observer_system.hpp"
#include "wilo_window.hpp"
#include "wilo_scriptable.hpp"
#include "wilo_console.hpp"
namespace wilo{
    /*

    
    
    */
    class Application: public Observer{
        public:
            Application();
            virtual void recieve(Message* msg);
            virtual void initialize();
            void run();
            virtual void reclaim();
            virtual ~Application();
        private:
            wilo::Window* m_main_window;//the main window for the application 
            wilo::Console* m_main_console;
            size_t m_id = 0;
            bool m_shutting_down = false;
    };
    
}