#include "InputDataContainer.h"


InputDataContainer::InputDataContainer()
: m_agID()
, m_evType()
, m_payload(0)
, m_location(0) 
{ //do nothing
}

void InputDataContainer::SetAgentID(const std::string& _agID)  
{ 
    m_agID = _agID; 
}

void InputDataContainer::SetEventType(const std::string& _eventType)  
{ 
    m_evType = _eventType; 
}

void InputDataContainer::SetPayload(const IData_t* _pdata)  
{ 
    m_payload = _pdata; 
}
 
void InputDataContainer::SetLocation(const Location_t* _location)  
{ 
    m_location = _location; 
}
  
const std::string& InputDataContainer::GetAgentID() const 
{ 
    return m_agID; 
}

const std::string& InputDataContainer::GetEventType() const 
{ 
    return m_evType; 
}

const IData_t* InputDataContainer::GetPayload() const 
{ 
    return m_payload; 
}
 
const Location_t* InputDataContainer::GetLocation() const 
{ 
    return m_location; 
}   
 

