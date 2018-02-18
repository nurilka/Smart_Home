
/** @file Sensor.cpp
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */
 
#include <cstdlib>  //rand(), srand()
#include <ctime>    //time()
#include <iostream>

#include "ambient_temp.h"

ambient_temp::ambient_temp(AgentData_t _agData)
: m_agData(_agData)
, m_sensTemp()
, m_eventTypes()
{ 
    m_eventTypes.insert("TEMP");
    m_eventTypes.insert("HEAT");
}


ambient_temp::~ambient_temp()
{ //do nothing
}

  
void ambient_temp::SendReading() //calls InputToServer of IAgent_t
{
    srand (time(NULL));
    m_sensTemp = rand()% 15 + 40;

    InputToServer((IData_t*)&m_sensTemp, "TEMP");
}


void ambient_temp::HandleEvent(shared_ptr<Event_t> _event)
{
    int* reading = (int*)_event->GetPayload();
    
    std::cout << "TEMP Controller: " << this->GetAgentID() << ", " 
    << this->GetLocation()->GetRoom() << ", " << this->GetLocation()->GetFloor() << std::endl;
    std::cout << "Event Info: " << _event->GetTimestamp() << " " << _event->GetEventType() << " " 
    << _event->GetLocation()->GetRoom() << " Reading: " << *reading << std::endl;
}


std::set<std::string> ambient_temp::GetAgentEventTypes()
{
    return m_eventTypes;
}

/*~~~~~~~~~~~~~~~~~~ Local ~~~~~~~~~~~~~~~~~~~~~~~*/
std::string ambient_temp::GetAgentID() const
{
    return m_agData.GetDeviceID();
}

const Location_t* ambient_temp::GetLocation() const
{
    Location_t* loc = new Location_t(m_agData.GetFloor(), m_agData.GetRoom());
   
    return loc;
}

/*~~~~~~~~~~~~~~~~~ Global ~~~~~~~~~~~~~~~~~~~~~*/

extern "C" ambient_temp* MakeAgent(AgentData_t _agData)
{
    return new ambient_temp(_agData);
}

extern "C" void DestroyAgent(ambient_temp* _agPtr)
{
    delete _agPtr;
}




