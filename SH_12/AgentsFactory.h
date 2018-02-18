#ifndef __AGENTSFACTORY_H__
#define __AGENTSFACTORY_H__


/** @file AgentsFactory.h
 *  @brief 
 *  
 * 
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


class SubsManager;
class EventGenerator;
class Configurator;
class AgentsContainer;
class ISoRegistry;
class IAgent_t;
class AgentData_t;

class AgentsFactory
{
public:
    
	typedef IAgent_t* (*MakeAgent)(AgentData_t);
	typedef void DestroyAgent(IAgent_t*);
    
    AgentsFactory(SubsManager* _sManager, EventGenerator* _eventGen
                  , Configurator* _cnfg, AgentsContainer* _agents
                  , ISoRegistry* _registry);  
    ~AgentsFactory();      
    
    void CreateAgents();   

private:
    SubsManager* m_sManager; 
    EventGenerator* m_eventGen;
    Configurator* m_configurator;
    AgentsContainer* m_agents;
    ISoRegistry* m_registry;
    

    void AddAgentAsSubscriber(IAgent_t* _agent);
    void AddAgentEvents(IAgent_t* _agent);    
    void AddAgentToContainer(IAgent_t* _agent);  
    
    AgentsFactory(const AgentsFactory& _other); 
    AgentsFactory& operator= (const AgentsFactory& _other);
};

#endif /* __AGENTSFACTORY_H__ */





