#ifndef __AMBIENT_TEMP__H__
#define __AMBIENT_TEMP__H__


/** @file ambient_temp.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs (yet).
 */

#include <string>

#include "../IAgent_t.h"
#include "../Location_t.h"
#include "../Event_t.h"
#include "../AgentData_t.h"

class ambient_temp: public IAgent_t
{
public:
    ambient_temp(AgentData_t _agData);
    ~ambient_temp();
    
    virtual std::string GetAgentID() const;
    virtual const Location_t* GetLocation() const;
    virtual void SendReading(); // has to call InputToServer, inherited from IAgent_t
    virtual void HandleEvent(shared_ptr<Event_t> _event); // I am a sub
    virtual std::set<std::string> GetAgentEventTypes();
    
private:
    AgentData_t m_agData;
    int m_sensTemp;
    std::set<std::string>  m_eventTypes;

    
    ambient_temp(const ambient_temp& _other);
    ambient_temp& operator= (const ambient_temp& _other);    
};


extern "C" ambient_temp* MakeAgent(AgentData_t _agData);
extern "C" void DestroyAgent(ambient_temp* _agPtr);


#endif /* __AMBIENT_TEMP__H__ */




