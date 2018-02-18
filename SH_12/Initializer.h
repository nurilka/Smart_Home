#ifndef __INITIALIZER_H__
#define __INITIALIZER_H__


/** @file Initializer.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include <string>

#include "SubsManager.h"
#include "Router.h"
#include "EventGenerator.h"
#include "Loader.h"
#include "SoRegistry.h"
#include "AgentsContainer.h"
#include "Configurator.h"
#include "AgentsFactory.h"

class Initializer
{
public:
    
    Initializer();  
    ~Initializer();      

    void InitializeAndRun(std::string _soDir, std::string _configFile);
    
    //for debug
    AgentsContainer* GetAgentsContainer() const;

private:

    //better to have all those as data members born here in the right order
    SubsManager* m_sMng;
    Router* m_router;  
    EventGenerator* m_evGen;
    Loader* m_loader;
    SoRegistry* m_reg;       
    AgentsContainer* m_agents;
    Configurator* m_cnfg;
    AgentsFactory* m_factory;
	
	Initializer(const Initializer& _other); 
    Initializer& operator= (const Initializer& _other);
    
};

#endif /* __INITIALIZER_H__ */





