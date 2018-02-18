
#include "Event_t.h" 


Event_t::Event_t()
: m_timestamp()
, m_evType()
, m_payload(0)
, m_location(0)
{ //do nothing
}

void Event_t::SetTimestamp(const std::string& _timestamp)  
{ 
    m_timestamp = _timestamp; 
}

void Event_t::SetEventType(const std::string& _eventType)  
{ 
    m_evType = _eventType; 
}

void Event_t::SetPayload(const IData_t* _pdata)  
{ 
    m_payload = _pdata; 
}
 
void Event_t::SetLocation(const Location_t* _location)  
{ 
    m_location = _location; 
}
  
const std::string& Event_t::GetTimestamp() const 
{ 
    return m_timestamp; 
}

const std::string& Event_t::GetEventType() const 
{ 
    return m_evType; 
}

const IData_t* Event_t::GetPayload() const 
{ 
    return m_payload; 
}
 
const Location_t* Event_t::GetLocation() const 
{ 
    return m_location; 
}   
 
