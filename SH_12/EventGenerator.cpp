
/** @file EventGenerator.cpp
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include "EventGenerator.h"
#include "Event_t.h"
//#include "Channel.h"

#include <ctime>

EventGenerator::EventGenerator(ISubscriber_t* _sub)
: m_sub (_sub)
{ //do nothing
}


EventGenerator::~EventGenerator() 
{ //do nothing
} 


const char* CreateTimeStamp() 
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    char* timestamp = asctime (timeinfo);
    return timestamp;
}


shared_ptr<Event_t> EventGenerator::GenerateEvent(shared_ptr<InputDataContainer> _input)  
{
    shared_ptr<Event_t> evt(new Event_t());
    
    evt->SetTimestamp(CreateTimeStamp());
    evt->SetEventType(_input->GetEventType());
    evt->SetPayload(_input->GetPayload());
    evt->SetLocation(_input->GetLocation());   
        
    //SendToChannel(evt);
    this->Notify((IData_t*)&evt);
    
    return evt;
} 


void EventGenerator::AddSubscriber(ISubscriber_t* _sub)//my subscriber is Router
{
    m_sub = _sub;
}

void EventGenerator::RemoveSubscriber(ISubscriber_t* _sub) 
{   //do nothing
}
    
void EventGenerator::Notify(IData_t* _data)
{
    m_sub->Update(_data);   //This is Router::Update()
}


void EventGenerator::Update(IData_t* _data)
{    
    GenerateEvent(*((shared_ptr<InputDataContainer>*)_data));  
}




/*void EventGenerator::SendToChannel(shared_ptr<Event_t> _event)
{
    m_eventsOut.Send(_event);
}*/



 

