#ifndef __EVENTGENERATOR_H__
#define __EVENTGENERATOR_H__


/** @file EventGenerator.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */

#include <tr1/memory>

#include "InputDataContainer.h"
#include "ISubscriber_t.h"
#include "IPublisher_t.h"


using std::tr1::shared_ptr;

class Event_t;
//class Channel;

class EventGenerator: public ISubscriber_t, public IPublisher_t
{
public:
    
    EventGenerator(ISubscriber_t* _sub);  //router subscribes on EventGen creation
    ~EventGenerator();      
    
    virtual void Notify(IData_t* _data);
    virtual void Update(IData_t* _pdata);

private:
   // shared_ptr<Event_t> m_event;
    //Channel&  m_eventsOut;
    ISubscriber_t* m_sub;
    
    shared_ptr<Event_t> GenerateEvent(shared_ptr<InputDataContainer> _input);
   // void SendToChannel(shared_ptr<Event_t> _event);
    
    virtual void AddSubscriber(ISubscriber_t* _sub);
    virtual void RemoveSubscriber(ISubscriber_t* _sub);
    EventGenerator(const EventGenerator& _other); 
    EventGenerator& operator= (const EventGenerator& _other);
};

#endif /* __EVENTGENERATOR_H__ */





