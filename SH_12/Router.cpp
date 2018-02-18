
/** @file Router.cpp
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */

#include <algorithm>
#include <iostream>

#include "Router.h"
#include "IAgent_t.h"
#include "Event_t.h"



Router::Router(SubsManager& _sManager/*, Channel& _channel*/)
: m_sManager(_sManager)
//, m_eventsIn(_channel)
{   //do nothing
}
  
Router::~Router()
{   //do nothing
}      

void Router::Notify(IData_t* _data) //router is a publisher for Agents
{
    std::set<IAgent_t*> sbs = GetSubscribers((*((shared_ptr<Event_t>*)_data))->GetEventType()); 
    
    std::set<IAgent_t*>::iterator it;  
    for (it = sbs.begin(); it != sbs.end(); ++it)
    {
        (*it)->Update(_data);   // IAgent_t::Update()
    }
}


void Router::Update(IData_t* _pdata) //router is a subscriber for EventGenerator
{
    this->Notify(_pdata);
}

//polling from channel
/*void Router::RouteAndDispatch()
{
    shared_ptr<Event_t> event = GetEventFromChannel();
    Notify((IData_t*)&event);
} 


shared_ptr<Event_t> Router::GetEventFromChannel() 
{
    return m_eventsIn.Receive();
}*/


std::set<IAgent_t*> Router::GetSubscribers(std::string _eventType) 
{
    return m_sManager.GetSubscribersList(_eventType);
}

void Router::AddSubscriber(ISubscriber_t* _sub) {}
void Router::RemoveSubscriber(ISubscriber_t* _sub) {}












