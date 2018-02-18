#ifndef __SUBSMANAGER_H__
#define __SUBSMANAGER_H__


/** @file SubsManager.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */

#include <map>
#include <set>
#include <string>


#include "IAgent_t.h"


class SubsManager
{
public:
    
    SubsManager();  
    ~SubsManager();
    //SubsManager(const SubsManager& _other); 
    //SubsManager& operator= (const SubsManager& _other);      

    std::set<IAgent_t*> GetSubscribersList(std::string _eventType);
    
    void SubscribeToEvent(IAgent_t* _agent, std::string _eventType);
    void UnSubscribeFromEvent(IAgent_t* _agent, std::string _eventType);


private:
    std::map<std::string, std::set<IAgent_t*> > m_subscribers;
    
};

#endif /* __SUBSMANAGER_H__ */





