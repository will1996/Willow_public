#include"wilo_engine_element.hpp"

namespace wilo {

	EngineElement::EngineElement()
	{
		m_ID = ObjectCounter::getCoreElementUniqueID();
	}

	EngineElement::EngineElement(wilo_ID_type id)
	{
		m_ID = id;
	}

	EngineElement::~EngineElement() {}
}