
/** @file SoRegistry.cpp
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */

#include <tr1/memory>
using std::tr1::shared_ptr;

#include "SoRegistry.h"
#include "AgentBuildData.h"

SoRegistry::SoRegistry(ILoader* _loader) 
: m_loader(_loader)
, m_agMake()
, m_agDestroy()
{ //do nothing
}

 
SoRegistry::~SoRegistry()
{ //do nothing
}

      
void* SoRegistry::GetCreateFunc(std::string _agentType)
{
    if ( m_agMake.find(_agentType) == m_agMake.end() )
    {
        shared_ptr<AgentBuildData> ptrBuild = m_loader->LoadSharedObject(_agentType);
    
        std::string agentType = ptrBuild->GetAgentType();
        RegisterCreate(ptrBuild->GetAgentMake(), agentType);
        RegisterDestroy(ptrBuild->GetAgentDestroy(), agentType); 
    }
    
    return m_agMake[_agentType];
}

void* SoRegistry::GetDestroyFunc(std::string _agentType)
{
    if ( m_agDestroy.find(_agentType) == m_agDestroy.end() )
    {
        shared_ptr<AgentBuildData> ptrBuild = m_loader->LoadSharedObject(_agentType);
    
        std::string agentType = ptrBuild->GetAgentType();
        RegisterCreate(ptrBuild->GetAgentMake(), agentType);
        RegisterDestroy(ptrBuild->GetAgentDestroy(), agentType); 
    }
      
    return m_agDestroy[_agentType];
}


void SoRegistry::RegisterCreate(void* _agentMake, std::string _agentType)
{
    m_agMake[_agentType] = _agentMake;
}

void SoRegistry::RemoveCreate(std::string _agentType)
{
    m_agMake.erase(_agentType);
}


void SoRegistry::RegisterDestroy(void* _agentDestr, std::string _agentType)
{
    m_agDestroy[_agentType] = _agentDestr;
}

void SoRegistry::RemoveDestroy(std::string _agentType)
{
    m_agDestroy.erase(_agentType);
}





