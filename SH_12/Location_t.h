#ifndef __LOCATION_T_H__
#define __LOCATION_T_H__


/** @file Location_t.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include <string>

class Location_t
{
public:
    Location_t(std::string _floor, std::string _room)
    : m_floor(_floor)
    , m_room(_room)
    {   //do nothing
    }
    //~Location_t();
    //Location_t(const Location_t& _other);
    //Location_t& operator= (const Location_t& _other);
    void SetRoom(std::string& _room)  {  m_room = _room; }
    void SetFloor(std::string& _floor)  { m_floor = _floor; }
    
    std::string GetRoom() const { return m_room; }
    std::string GetFloor() const { return m_floor; }
    
private:
    std::string m_floor;	
    std::string m_room;
};

#endif /* __LOCATION_T_H__ */




