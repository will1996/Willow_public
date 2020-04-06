#include "wilo_console.hpp"

namespace wilo{
    Console::Console():Scriptable<Console>("console"){
        //m_LuaBindings = {"quit",quit};
        //Scriptable::register(this);
        this->LT_appendMember<&Console::quit>("quit");
    }
    Console::~Console(){
        //do nothing
    }
    void Console::initialize(){
        //TODO write helper functions to allow initialization to read from a file, or hard code it here.
        lua_pushstring(m_L,"test passed!");
        lua_setglobal(m_L,"my_global");

        WILO_CORE_INFO("console initialized!")

    }
    void checklua(lua_State* L, int res){
        if(res != LUA_OK){
           std::string errmsg = lua_tostring(L,-1);
           std::cout<<"[LUA_ERROR] "<<errmsg<<std::endl;
        }
    }
    void Console::evaluate( std::string command ){
        checklua(m_L,luaL_dostring(m_L,command.c_str()));
    }

    void Console::setScriptPath(std::string path){
    }

    void Console::reclaim(){
    }

    void Console::checkIn(){
        checklua(m_L,luaL_dofile(m_L,"/Users/willchambers/Projects/astral/wilo/scripts_engine/startup.lua"));
    }

    void Console::notifyWindowObservers(WindowMessage * msg){
        Subject::notify<WindowMessage>(msg);
    }

    int Console::quit(::lua_State* L ){
        WindowMessage::Info info;
        info.title = "app window";
        WindowMessage * msg = new WindowMessage(MessageType::WindowClose,info);
        notifyWindowObservers(msg);
        return 0;
    }




}