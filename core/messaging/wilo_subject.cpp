#include "wilo_subject.hpp"
#include "wilo_observer.hpp"
#include "wilo_message.hpp"



namespace wilo{
    //add and remove observers from internal observers map
    //definition moved to header to see if that resolves linker issues
//        template<typename O,typename M, void(O::*Method)(M& m) >
//    void Subject::permit(O* obs);
//        m_observers[obs->getId()] = obs;
//
//    }
//    void Subject::revoke(Observer* obs){
//        throw std::runtime_error("Unimplemented");
//    }
//    void Subject::notifyAll(Message& message){
//        throw std::runtime_error("Uniplemented");
//    }
        
}