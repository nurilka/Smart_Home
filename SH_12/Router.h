#ifndef __ROUTER_H__
#define __ROUTER_H__


/** @file Router.h
 *  @brief 
 *  
 *  Router is a IPublisher_t for IAgent_t (That subscribed to events)
 *  Router is a ISubscriber_t for EventGenerator (cancelles polling the queue changes)
 * 
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */

#include <tr1/memory>
#include <set>

#include "SubsManager.h"
//#include "Channel.h"
#include "IPublisher_t.h"
#include "ISubscriber_t.h"

using std::tr1::shared_ptr;

class Event_t;
class IAgent_t;

class Router: public IPublisher_t, public ISubscriber_t
{
public:
    
    Router(SubsManager& _sManager/*, Channel& _channel*/);  
    ~Router();      
   
    virtual void Notify(IData_t* _data);
    virtual void Update(IData_t* _pdata);
    
    //void RouteAndDispatch();


private:
    SubsManager& m_sManager;
    
    std::set<IAgent_t*> GetSubscribers(std::string _type);
    //Channel&     m_eventsIn;  
    //shared_ptr<Event_t> GetEventFromChannel();
    //void DispatchEvent(shared_ptr<Event_t> _event);
    
    virtual void AddSubscriber(ISubscriber_t* _sub);    //no impl
    virtual void RemoveSubscriber(ISubscriber_t* _sub); //no impl   
    Router(const Router& _other); 
    Router& operator= (const Router& _other);
};

#endif /* __ROUTER_H__ */





