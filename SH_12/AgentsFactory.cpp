
    
/** @file AgentsFactory.cpp
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs (yet).
 */
 
#include <queue>

#include "AgentsFactory.h"

#include "SubsManager.h"
#include "EventGenerator.h"
#include "Configurator.h"
#include "AgentsContainer.h"
#include "ISoRegistry.h"
#include "AgentData_t.h"
#include "IAgent_t.h"

AgentsFactory::AgentsFactory(SubsManager* _sManager
                             , EventGenerator* _eventGen
                             , Configurator* _cnfg
                             , AgentsContainer* _agents
                             , ISoRegistry* _registry)
: m_sManager(_sManager)
, m_eventGen(_eventGen)
, m_configurator(_cnfg)
, m_agents(_agents)
, m_registry(_registry)
{   //do nothing
}

 
AgentsFactory::~AgentsFactory()
{   //do nothing
}      


void AgentsFactory::CreateAgents()
{    
    std::queue<AgentData_t> agDataSet = m_configurator->GetAgentData();
    AgentData_t data;
    
//    typedef IAgent_t* (*MakeAgent)(AgentData_t _agData);
//	typedef void (*DestroyAgent)(IAgent_t* _agPtr);
    
    
    while ( !agDataSet.empty() )
    {
        data = agDataSet.front();
        agDataSet.pop();
        IAgent_t* agent(0);
        
        void* fnPtr = m_registry->GetCreateFunc(data.GetDeviceType());
        if (fnPtr)
        {
            MakeAgent* make = (MakeAgent*)&fnPtr;
            agent = (*make)(data);
            AddAgentAsSubscriber(agent);
            AddAgentEvents(agent);
            AddAgentToContainer(agent);
        }
    }
}



void AgentsFactory::AddAgentAsSubscriber(IAgent_t* _agent)
{      
    _agent->AddSubscriber(m_eventGen);
}

   
void AgentsFactory::AddAgentEvents(IAgent_t* _agent)    
{
    std::set<std::string> evtList = _agent->GetAgentEventTypes();
    std::set<std::string>::iterator itr;  
    for (itr = evtList.begin(); itr != evtList.end(); ++itr)
    {
        std::string evtType = (*itr);
        m_sManager->SubscribeToEvent(_agent, evtType);
    }
}


void AgentsFactory::AddAgentToContainer(IAgent_t* _agent)
{
    m_agents->AddToContainer(_agent);
}
    







