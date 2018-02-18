
/** @file SubsManager.cpp
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include "SubsManager.h"

SubsManager::SubsManager()
: m_subscribers()
{ //do nothing
}

 
SubsManager::~SubsManager()
{ //do nothing
}      

std::set<IAgent_t*> SubsManager::GetSubscribersList(std::string _eventType)
{
    return m_subscribers[_eventType];
}

void SubsManager::SubscribeToEvent( IAgent_t* _agent, std::string _eventType)
{
    m_subscribers[_eventType].insert(_agent);
}


void SubsManager::UnSubscribeFromEvent( IAgent_t* _agent, std::string _eventType)
{
    m_subscribers[_eventType].erase(_agent);
}









