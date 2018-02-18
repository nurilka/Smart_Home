
/** @file Initializer.cpp
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */



#include "Initializer.h"


Initializer::Initializer()
: m_sMng(0)
, m_router(0)  
, m_evGen(0)
, m_loader(0)
, m_reg(0)      
, m_agents(0)
, m_cnfg(0)
, m_factory(0)
{
}
  
Initializer::~Initializer()
{
    if ( m_factory ) { delete m_factory; }
    if ( m_cnfg ) { delete m_cnfg; }
    if ( m_agents ) { delete m_agents; }
    if ( m_reg ) { delete m_reg; }
    if ( m_loader ) { delete m_loader; }
    if ( m_evGen ) { delete m_evGen; }
    if ( m_router ) { delete m_router; }
    if ( m_sMng ) { delete m_sMng; }
}      

void Initializer::InitializeAndRun(std::string _soDir, std::string _configFile)
{
    try {
        m_sMng  = new SubsManager;
        m_router = new Router(*m_sMng);  
        m_evGen = new EventGenerator(m_router);
        m_loader = new Loader(_soDir);
        m_reg = new SoRegistry(m_loader);
            
        m_agents = new AgentsContainer;
        m_cnfg = new Configurator(_configFile);
        m_factory = new AgentsFactory(m_sMng, m_evGen, m_cnfg, m_agents, m_reg);
    } catch (...)
    {
        if ( m_factory ) { delete m_factory; }
        if ( m_cnfg ) { delete m_cnfg; }
        if ( m_agents ) { delete m_agents; }
        if ( m_reg ) { delete m_reg; }
        if ( m_loader ) { delete m_loader; }
        if ( m_evGen ) { delete m_evGen; }
        if ( m_router ) { delete m_router; }
        if ( m_sMng ) { delete m_sMng; }
        return;
    }
   
    m_factory->CreateAgents();
}


AgentsContainer* Initializer::GetAgentsContainer() const
{
    return m_agents;
}




