#include "wilo_console.hpp"
namespace wilo{
    Console::Console():Scriptable<Console>("console",this),m_testScriptsPath(WILO_TESTS_SCRIPTS_PATH),m_engineScriptsPath(WILO_ENGINE_SCRIPTS_PATH){
        this->LT_appendMember<&Console::quit>("quit");
        this->LT_appendMember<&Console::resize>("resize");
        this->LT_appendMember<&Console::setMouse>("setMouse");
        this->LT_appendMember<&Console::pressKey>("pressKey");
        this->LT_appendMember<&Console::reinitialize>("reinitialize");
        this->L_setglobal("tests_path",m_testScriptsPath);
        this->L_runScript(m_testScriptsPath + "testing_base.lua");
    }
    Console::~Console(){
        //do nothing
    }
    void Console::initialize(){
        L_runScript(m_engineScriptsPath + "console_base.lua");
        a_should_stop = false;
        WILO_CORE_INFO("console initialized!")

    }
   
    void Console::evaluate( std::string command ){
        L_runScript(command);
    }

    using namespace std::literals::chrono_literals;//give me the use of "s" for seconds
    void Console::thread_loop(){
        while (!a_should_stop) {
            char command_buf[256];
            std::cout << "Lua>> ";
            std::cin.getline(command_buf, 256);
            std::string command(command_buf);
            evaluate(command);
            std::this_thread::sleep_for(.1s);
        }
    }
    
    void Console::run() {
        m_thread = std::thread(&Console::thread_loop, this);
    }

    void Console::setScriptPath(std::string path){
        m_userScriptsPath = path;
    }

    void Console::reclaim(){
        WILO_CORE_INFO("console reclamation started");
        
        a_should_stop = true;
        m_thread.join();
        WILO_CORE_INFO("console shutdown properly");
    }

    Subject* Console::asSubject()
    {
        return &this->subject;
    }

    void Console::checkIn(){
        throw std::runtime_error("UNIMPLEMENTED");
    }

    void Console::notifyWindowObservers(const wilo::WindowMessage& msg){
        subject.notify<WindowMessage>(msg);
    }

    void Console::notifyMouseObservers(const wilo::MouseMessage& msg)
    {
        subject.notify<MouseMessage>(msg);
    }

    void Console::notifyKeyboardObservers(const wilo::KeyboardMessage& msg)
    {
        subject.notify<KeyboardMessage>(msg);
    }

    int Console::quit(::lua_State* L ){
        WindowMessage::Info info;
        info.title = "app window";
        notifyWindowObservers( wilo::WindowMessage(MessageType::WindowClose,info));
        return 0;
    }


    int Console::resize(::lua_State* L){
        int width = ::lua_tointeger(L, 1);
        int height = ::lua_tointeger(L, 2);

        WindowMessage::Info info;
        info.title = "app window";
        info.height = height;
        info.width = width;

        notifyWindowObservers( wilo::WindowMessage(MessageType::WindowResized, info));
        return 0;
    }

    int Console::setMouse(::lua_State* L)
    {
        int x = ::lua_tointeger(L, 1);
        int y = ::lua_tointeger(L, 2);
        MouseMessage::Info info;
        info.xPos = x;
        info.yPos = x;
        notifyMouseObservers( wilo::MouseMessage(MessageType::MouseMoved,info));
        return 0;
    }

    int Console::pressKey(::lua_State* L)
    {
        int code = ::lua_tointeger(L, -1);
        KeyboardMessage::Info info;
        info.button = wilo::KeyCode(code);
        notifyKeyboardObservers( wilo::KeyboardMessage(MessageType::KeyPressed, info));
        return 0;
    }
    int Console::reinitialize(::lua_State* L){
        L_runScript(m_engineScriptsPath + "console_base.lua");
        L_runScript(m_testScriptsPath + "testing_base.lua");
#ifndef ndebug
        Scriptable::L_reinitialize();
#endif
        return 0;
    }
}