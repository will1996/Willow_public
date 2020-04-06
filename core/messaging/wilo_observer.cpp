#include "wilo_observer.hpp" 
#include "wilo_subject.hpp" 



namespace wilo{
   // Observer::Observer(){};
    void Observer::reclaim(){
        for(auto *sub : m_subjects){
            sub->revoke(this->getID());
        }
    }
    Observer::~Observer(){
        
    }


}