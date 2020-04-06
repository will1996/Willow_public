#pragma once
#include "wilo_dev_core.hpp"
#include "wilo_message.hpp"
namespace wilo{
class Observer{
   friend class Subject;
   public:
    Observer(){
         m_uniqueID = ObjectCounter::getUniqueID();//assign unique ID from global object counter;
    }
    void reclaim();
    virtual ~Observer();
    wilo_ID_type  getID(){
        return m_uniqueID;
    }
    
   private:
    //we need this list of subjects to notify when this obererver is freed, this is how we populate that list.
    void trackSubject(Subject* sub){
        m_subjects.push_back(sub);
    }
    wilo_ID_type m_uniqueID;
    std::vector<Subject*> m_subjects;
};
}