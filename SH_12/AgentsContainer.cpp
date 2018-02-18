

/** @file AgentsContainer.cpp
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include "AgentsContainer.h"

AgentsContainer::AgentsContainer()
: m_agents()
{
}  

AgentsContainer::~AgentsContainer() //delete all IAgent_t*
{
    std::map<std::string, IAgent_t*>::iterator it;
    for (it = m_agents.begin(); it != m_agents.end(); ++it)
    {
      delete (it->second);
    }
}

IAgent_t* AgentsContainer::GetAgent(std::string _agentID)
{
    return m_agents[_agentID];
}

void AgentsContainer::AddToContainer(IAgent_t* _pAgent)
{
    std::string currID = _pAgent->GetAgentID();
    m_agents[currID] = _pAgent;
}


void AgentsContainer::RemoveFromContainer(IAgent_t* _pAgent)
{
    std::string currID = _pAgent->GetAgentID();
    m_agents.erase (currID);
}











