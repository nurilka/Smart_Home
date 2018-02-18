#ifndef __AGENTDATA_T_H__
#define __AGENTDATA_T_H__


/** @file AgentData_t.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs (yet).
 */

#include <string>

class AgentData_t
{
public:
    AgentData_t() 
    : m_deviceID()	    
    , m_type()	
    , m_room()	
    , m_floor()	
    , m_log()	
    , m_config()
    {
    }
    //~AgentData_t();
    //AgentData_t(const AgentData_t& _other);
    //AgentData_t& operator= (const AgentData_t& _other); 
    
    void SetDeviceID(std::string _deviceID) { m_deviceID = _deviceID; }
    void SetDeviceType(std::string _type) { m_type = _type; }
    void SetRoom(std::string _room) { m_room = _room; }
    void SetFloor(std::string _floor) { m_floor = _floor; }
    void SetLog(std::string _log) { m_log = _log; }
    void SetConfig(std::string _config) { m_config = _config; }
    
    const std::string GetDeviceID() const { return m_deviceID; }
    const std::string GetDeviceType() const { return m_type; }
    const std::string GetRoom() const { return m_room; }
    const std::string GetFloor() const { return m_floor; }
    const std::string GetLog() const { return m_log; }
    const std::string GetConfig() const { return m_config; }

private:
    std::string m_deviceID;	    
    std::string m_type;	
    std::string m_room;	
    std::string m_floor;	
    std::string m_log;	
    std::string m_config;
       
};

#endif /* __AGENTDATA_T_H__ */





