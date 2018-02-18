#ifndef __EVENT_T_H__
#define __EVENT_T_H__


/** @file Event_t.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include <string>
#include "Location_t.h"
#include "IData_t.h"  



class Event_t
{
public:
    
    Event_t();
    //~Event_t();      

    
    void SetTimestamp(const std::string& _timestamp);
    void SetEventType(const std::string& _eventType);
    void SetPayload(const IData_t*_pdata); 
    void SetLocation(const Location_t* _location);
    
    
    const std::string& GetTimestamp() const;
    const std::string& GetEventType() const;
    const IData_t* GetPayload() const; 
    const Location_t* GetLocation() const;

private:
    std::string m_timestamp;
    std::string m_evType;
    const IData_t* m_payload;
    const Location_t* m_location;
    

    Event_t(const Event_t& _other); 
    Event_t& operator= (const Event_t& _other);
};


#endif /* __EVENT_T_H__ */
