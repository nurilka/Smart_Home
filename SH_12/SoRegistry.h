#ifndef __SOREGISTRY_H__
#define __SOREGISTRY_H__


/** @file SoRegistry.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */

#include <map>
#include <string>


#include "ISoRegistry.h"


class SoRegistry: public ISoRegistry
{
public:
    
    SoRegistry(ILoader* _loader);  
    virtual ~SoRegistry();      

    virtual void* GetCreateFunc(std::string _agentType);
    virtual void* GetDestroyFunc(std::string _agentType);
    
    virtual void RegisterCreate(void* _agentMake, std::string _agentType);
    virtual void RemoveCreate(std::string _agentType);
    
    virtual void RegisterDestroy(void* _agentDestr, std::string _agentType);
    virtual void RemoveDestroy(std::string _agentType);

private:
	ILoader* m_loader;
	std::map <std::string, void*> m_agMake;
	std::map <std::string, void*> m_agDestroy;
	
	SoRegistry(const SoRegistry& _other); 
    SoRegistry& operator= (const SoRegistry& _other);
    
};

#endif /* __SOREGISTRY_H__ */





