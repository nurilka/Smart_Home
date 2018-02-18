

/** @file IAgent_t.cpp
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs (yet).
 */
#include "IAgent_t.h"

#include "Event_t.h"
#include "Location_t.h"
#include "InputDataContainer.h"

IAgent_t::IAgent_t()
: m_sub(0)
//: m_myEvents()
{   //do nothing
}


IAgent_t::~IAgent_t()
{   //do nothing
}
  
/*~~~~~~~~~~~~~~~~~~ PUBLISHER ~~~~~~~~~~~~~~~~~~~~~~~*/
void IAgent_t::AddSubscriber(ISubscriber_t* _sub)   //EventGenerator is an ISubscriber_t
{
    m_sub = _sub;
}


void IAgent_t::RemoveSubscriber(ISubscriber_t* _sub)
{   //do nothing
}


void IAgent_t::InputToServer(IData_t* _data, std::string _eventType)
{
    shared_ptr<InputDataContainer> pIDC(new InputDataContainer);
    //InputDataContainer* pIDC = new InputDataContainer;  //try catch
    
    pIDC->SetLocation(this->GetLocation());
    pIDC->SetAgentID(this->GetAgentID());
    pIDC->SetEventType(_eventType);
    pIDC->SetPayload(_data); 
    
    this->Notify((IData_t*)&pIDC); 
}


void IAgent_t::Notify(IData_t* _data)
{
    m_sub->Update(_data);  //my ISub is EventGenerator
}

/*~~~~~~~~~~~~~~~~~~ SUBSCRIBER ~~~~~~~~~~~~~~~~~~~~~~~*/
void IAgent_t::Update(IData_t* _pdata)
{
    HandleEvent(*((shared_ptr<Event_t>*)_pdata));  
}




 
    

