#ifndef WILO_ENGINE_COMPONENT_H
#define WILO_ENGINE_COMPONENT_H
#include "wilo_object_counter.hpp"
namespace wilo {

	class EngineElement{
		/*base engine component for wilo, contains an ID, from the object counter as well as the pure virtual methods initiaze and reclaim */
	public:
		EngineElement();
		EngineElement(wilo_ID_type);

		virtual ~EngineElement();


		virtual void initialize() = 0;
		virtual void reclaim() = 0;
		protected:
		wilo_ID_type m_ID;
		};


}
#endif