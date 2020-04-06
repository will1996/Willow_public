#pragma once
#include "lua.hpp"
#include "wilo_dev_core.hpp"
#include "wilo_subject.hpp"
#include "wilo_observer.hpp"
#include "wilo_lua_tools.hpp"
#define WILO_SCRIPTABLE_BASE_SCRIPT = "/Users/willchambers/Projects/astral/wilo/scripts_engine/scriptable_base.lua"
//TODO add Cmake defined install settings header, which specifies scriptable base script
namespace wilo{
    /*base class for scripted objects that are to be accessed both from Lua
    and from C++. Scriptables 
    Scriptables correspond to global tables in their Lua global environment stored
    in thier lua_States. On instantiation, we can choose to share a lua state with another
    scriptable by passing a const refernce to another scriptable into the constructor. 
    This allows us to build up a lua environment with access to many wilo objects without these
    objects needing to know anything about eachother other than that they are both scriptables. 
    In this way we can keep engine components decoupled, but still manage them from Lua. 

    There is one funky trick to using a Scriptable, for type saftey and speed you 
    have to use scriptable like: 

        class Childclass : public Scriptable<Childclass>{}

    On the front end this just lets us use less verbose calls to scriptable protected
    functions like LT_appendMember. On the back end it enforces a certain amount of type saftey. 
    for instance there is no way to bind a member function of a type other than the child class. 

    Finally, Scriptables expose a second kind of inter-object communication to wilo: direct dispatch. 

    while the observer system allows for barely coupled objects to recieve broadcasts about particular
    events without the subject needing to know anything about the observer, the lua dispatch system
    requires that the sender of the message knows precisely who it's talking to. 

    This would introduce a good deal of coupling, except that we're doing it through Lua, using a similar interface
    to the one we use to register observers. 

    
    //TODO implement tracking of scriptables in the global environment (maybe)
    */

        template <class T>
    class Scriptable{
        //static std::vector<std::pair<std::string,lua_State*>> Instances;
        public:
            
        
        //build a new scriptable with a name, and fresh Lua environment
        //this will create the lua table corresponding to THIS scriptable, and 
        //run the scriptable_lua base script to do the base lua configuration
        Scriptable(std::string name ): m_L(::luaL_newstate()),m_name(name){
            ::luaL_openlibs(m_L);
            runBaseScript();
            LT_instantiate();
        }
        //build a scriptable into an existing Lua state. 
        //this will only create the lua table corresponding to THIS scriptable,
        //since the existing scriptable has already run its lua environment
        Scriptable(Scriptable & other , std::string name ) : m_L(other->m_L),m_name(name){
            LT_instantiate();
        }

        virtual ~Scriptable(){}
        protected:
        //Grant the oppourtunity to refine the Lua environment that is coarsely
        //defined by the LT methods. Since this Lua script has access to 
        //all of the globals henceforth defined in the lua state, we can do 
        //almost anything we want here, it is intended to restrict access 
        //and built structure into the otherwise almost completely plastic 
        //Lua environemtn
        virtual void initialize() = 0;
        ::lua_State*  m_L;
        std::string m_name;

            template< int(T::*Method)(lua_State*)>
        //add the member function in the template to this Luatable with the name "name"
        void LT_appendMember(std::string name){
            lua_getglobal(m_L,m_name.c_str());//retrieve the class table from the global namespace

            lua_pushstring(m_L,name.c_str());//push a key value pair of the string name
            lua_pushcfunction(m_L,call<Method>);//and the function call<Method>

            lua_settable(m_L,-3);//push the pair into the table

            lua_setglobal(m_L,m_name.c_str());//update the global variable with the new entries
        }

    private: 
        //invoke the template method on the 'this' pointer, calling a non-static member function
            template<int(T::*Method)(lua_State* L) >
        static int call(lua_State* L){
            lua_pushstring(L,"this");
            lua_gettable(L,-2);
            T* this_ptr = static_cast<T*> (lua_touserdata(L,-1));
            return (this_ptr->*Method)(L);
        }

        void runBaseScript(){
            int res = luaL_dofile(m_L,WILO_SCRIPTABLE_BASE_SCRIPT)
            if(res != LUA_OK) {
                #ifndef NDEBUG
                std::string msg = lua_tostring(m_L,-1);
                raise std::runtime_error("invalid Lua_base script, failed with:  "+ msg);
                #else    
                raise runtime_error("invalid Lua_base script please validate your install");
                #endif
            }
            
        }

      void LT_failOnNameConflict(){
            lua_getglobal(m_L,m_name.c_str());
            
            if (not lua_isnil(L,-1) ) {
                throw std::runtime_error("invalid Lua configuration, name "+m_name+" is already in this lua Namespace")
            }
        }

        //build a global table in Lua with the name m_name, and a reference to this object
        //failing if a global table of the same name already exists
        void LT_instantiate(){

            LT_failOnNameConflict();

           lua_newtable(m_L);//push a fresh table onto the stack 

           lua_pushstring(m_L,"this");//push a key value pair of the string "this"
           lua_pushlightuserdata(m_L,this);// and the value a pointer to 'this'

           lua_settable(m_L,1);//add the pair to the table

           lua_setglobal(m_L,m_name.c_str());//name the table, and pop it from the stack
        }

        void LT_destruct(){
            lua_pushnil(m_L);
            lua_setglobal(m_L,m_name.c_str());
        } 

    };

}
