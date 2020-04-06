#include"wilo_dev_core.hpp"
#include"wilo_subject.hpp"
#include "window_message.hpp"
#include"wilo_scriptable.hpp"
#include"lua.hpp"


namespace wilo{
    class Console: public Subject, public Scriptable<Console> {
        friend class Scriptable<Console>;
        public:
        Console();
        ~Console();
        void initialize() override ;
        void evaluate(std::string command);
        void checkIn();
        void reclaim();
        void setScriptPath(std::string path);
        private:
        void notifyWindowObservers(wilo::WindowMessage *msg);
        int quit(::lua_State *L);
    };

}