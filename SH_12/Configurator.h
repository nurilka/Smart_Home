#ifndef __CONFIGURATOR_H__
#define __CONFIGURATOR_H__


/** @file Configurator.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs (yet).
 */


#include <string>
#include <queue>
#include <fstream>

class AgentData_t;

class Configurator
{
public:
    Configurator(std::string _fileName);
    ~Configurator();
    
	std::queue<AgentData_t> GetAgentData();

private:
    std::fstream m_fName; 
    std::queue<AgentData_t> m_agentsCfg;

   
    Configurator(const Configurator& _other); 
    Configurator& operator=(const Configurator& _other);
};

#endif /*__CONFIGURATOR_H__*/
