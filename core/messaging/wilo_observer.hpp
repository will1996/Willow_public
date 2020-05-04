#pragma once
#include "wilo_dev_core.hpp"
#include "wilo_object_counter.hpp"
#include "wilo_message.hpp"
#include "wilo_engine_element.hpp"
namespace wilo{
    class Subject;
class Observer  : public EngineElement{
   friend class Subject;
   public:
       Observer();
       Observer(wilo_ID_type id);
    
    void reclaim() override;
    void initialize() override;
    virtual ~Observer();

    wilo_ID_type  getID(){
        return m_ID;
    }
    
   private:
    //we need this list of subjects to notify when this obererver is freed, this is how we populate that list.
    void trackSubject(Subject* sub){
        m_subjects.push_back(sub);
    }
    std::vector<Subject*> m_subjects;
};
}