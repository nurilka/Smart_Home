#ifndef __INPUTDATACONTAINER_H__
#define __INPUTDATACONTAINER_H__


/** @file InputDataContainer.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include <string>
#include "Location_t.h"
#include "IData_t.h"




class InputDataContainer
{
public:
    
    InputDataContainer();
    //~InputDataContainer();      

    
    void SetAgentID(const std::string& _agID);
    void SetEventType(const std::string& _eventType);
    void SetPayload(const IData_t*_pdata); 
    void SetLocation(const Location_t* _location);
    
    
    const std::string& GetAgentID() const;
    const std::string& GetEventType() const;
    const IData_t* GetPayload() const; 
    const Location_t* GetLocation() const;

private:
    std::string m_agID;
    std::string m_evType;
    const IData_t* m_payload;
    const Location_t* m_location;
    

    InputDataContainer(const InputDataContainer& _other); 
    InputDataContainer& operator= (const InputDataContainer& _other);
};


#endif /* __INPUTDATACONTAINER_H__ */
