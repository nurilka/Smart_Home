#ifndef __IAGENT_T_H__
#define __IAGENT_T_H__


/** @file IAgent_t.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs (yet).
 */
#include <tr1/memory>
#include <string>
#include <set>

//#include "Channel.h"
#include "IPublisher_t.h"
#include "ISubscriber_t.h"



using std::tr1::shared_ptr;


class Event_t;
class Location_t;

class IAgent_t: public IPublisher_t, public ISubscriber_t
{
public:
    IAgent_t();
    virtual ~IAgent_t();
    
    //Publisher fucntions
    virtual void AddSubscriber(ISubscriber_t* _sub);
    virtual void SendReading() = 0; // has to call GenerateData 
    
    //Subscriber Funcions
    virtual void Update(IData_t* _pdata);   //calls ReceiveEvent
    virtual void HandleEvent(shared_ptr<Event_t> _event) = 0; // I am a sub
    virtual std::set<std::string> GetAgentEventTypes() = 0;
    
    //whoever inherits from me additionally has to implement
    virtual std::string GetAgentID() const = 0;
    virtual const Location_t* GetLocation() const = 0;
    
protected:
    void InputToServer(IData_t* _data, std::string _eventType); //I am a pub

private:
    //Channel         m_myEvents; //I am a sub 
    ISubscriber_t*  m_sub;  //my subscriber (eventManager), I am a pub
    
    //Publisher fucntions
    virtual void RemoveSubscriber(ISubscriber_t* _sub);
    virtual void Notify(IData_t* _data);
        
    IAgent_t(const IAgent_t& _other);
    IAgent_t& operator= (const IAgent_t& _other);    
};

#endif /* __IAGENT_T_H__ */





 
    

