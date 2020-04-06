#pragma once
#include<stdint.h>
#include<atomic>
namespace wilo{
    
 typedef uint32_t wilo_ID_type;

class ObjectCounter{
    /*quick and dirty, but also threadsafe ID maker*/
    //TODO make this actually threadsafe
    public: 
    static wilo_ID_type getCoreElementUniqueID(){return m_engineElementCounter++;} 
    static wilo_ID_type getComponentUniqueID(){return m_componentCounter++;}
    static wilo_ID_type getEntityUniqueID(){return m_entityCounter++;}
    private: 
    static wilo_ID_type m_engineElementCounter;
    static wilo_ID_type m_componentCounter;
    static wilo_ID_type m_entityCounter;
};
}