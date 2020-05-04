#include "wilo_observer.hpp" 
#include "wilo_subject.hpp" 



namespace wilo{
    Observer::Observer(){};
    Observer::Observer(wilo_ID_type id ): EngineElement(id){};
    void Observer::reclaim(){
        for(auto *sub : m_subjects){
            sub->revoke(this->getID());
        }
    }
    void Observer::initialize()
    {
    }
    Observer::~Observer(){
        
    }


}