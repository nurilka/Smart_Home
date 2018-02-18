#ifndef __AGENTSCONTAINER_H__
#define __AGENTSCONTAINER_H__


/** @file AgentsContainer.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */

#include <map>
#include <string>


#include "IAgent_t.h"


class AgentsContainer
{
public:
    
    AgentsContainer();  
    ~AgentsContainer();
    //AgentsContainer(const AgentsContainer& _other); 
    //AgentsContainer& operator= (const AgentsContainer& _other);      
    
    void AddToContainer(IAgent_t* _pAgent);
    void RemoveFromContainer(IAgent_t* _pAgent);
    IAgent_t* GetAgent(std::string _agentID);  

private:
    std::map<std::string, IAgent_t* > m_agents; //string - agentID, IAgent_t* - ptr to agent from factory
    //TODO receive Destroy functon ptr in AddToContainer
    //TODO hold a map by agentType and DestroyFunction
    //TODO in DTOR use the DestroyFunction for each Agent in container
};

#endif /* __AGENTSCONTAINER_H__ */





