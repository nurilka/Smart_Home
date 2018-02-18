#ifndef __ISOREGISTRY_H__
#define __ISOREGISTRY_H__


/** @file ISoRegistry.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include <string>

#include "IAgent_t.h"
#include "ILoader.h"

class ISoRegistry
{
public:
    ISoRegistry() {}
    ISoRegistry(ILoader* _loader);  
    virtual ~ISoRegistry() { }      

    virtual void* GetCreateFunc(std::string _agentType) = 0;
    virtual void* GetDestroyFunc(std::string _agentType) = 0;
    
    virtual void RegisterCreate(void* _agentMake, std::string _agentType) = 0;
    virtual void RemoveCreate(std::string _agentType) = 0;
    
    virtual void RegisterDestroy(void* _agentDestr, std::string _agentType) = 0;
    virtual void RemoveDestroy(std::string _agentType) = 0;

private:
    
};

#endif /* __ISOREGISTRY_H__ */





