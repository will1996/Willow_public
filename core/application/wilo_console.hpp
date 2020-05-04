#include"wilo_dev_core.hpp"
#include"wilo_subject.hpp"
#include "window_message.hpp"
#include "mouse_message.hpp"
#include "keyboard_message.hpp"
#include"wilo_scriptable.hpp"
#include<thread>
#include<atomic>
#include"lua.hpp"




namespace wilo{
    class Console : public Scriptable<Console> {
    public:
        Console();
        ~Console();
        void initialize() override;
        void evaluate(std::string command);
        void run();
        void checkIn();
        void reclaim();
        Subject* asSubject();

    
        void setScriptPath(std::string path);


        private:
        std::thread m_thread;
        const std::string m_testScriptsPath;
        const std::string m_engineScriptsPath;
        std::string m_userScriptsPath;
        Subject subject;
        void notifyWindowObservers  (const wilo::WindowMessage& msg);
        void notifyMouseObservers   (const wilo::MouseMessage& msg);
        void notifyKeyboardObservers(const wilo::KeyboardMessage& msg);
        void thread_loop();
        int quit(::lua_State *L);
        int resize(::lua_State* L);
        int setMouse(::lua_State* L);
        int pressKey(::lua_State* L);
        int reinitialize(::lua_State* L);
        std::atomic_bool a_should_stop;
    };

}