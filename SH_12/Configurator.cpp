#include <string>
#include <cstdio>
#include <cstring>

#include "AgentData_t.h"
#include "Configurator.h"


//using namespace std;

Configurator::Configurator(std::string _fileName)
: m_fName(_fileName.data()) 
, m_agentsCfg()
{   //do nothing
}
        
Configurator::~Configurator() 
{
    m_fName.close();
}

std::queue<AgentData_t> Configurator::GetAgentData()
{ 
    std::string lineNoWS; 
    std::string currStr;
    char key [256], value[256];
    AgentData_t agData;
    
    while (!m_fName.eof()) 
    {
        //if( m_fName.eof() ) break;  
    
        std::getline(m_fName, currStr);
        while (currStr == "\n\t")
        {
           std::getline(m_fName, currStr); 
        }
        
        
        sscanf(currStr.c_str(), "[%255[^]]]", value); 
        currStr = value;
        agData.SetDeviceID(currStr);

        
        std::getline(m_fName, currStr);
        sscanf(currStr.c_str(),"%s = %[^\t\n]", key, value);       
        if ( strcmp("type", key) == 0 )
        {
             currStr = value;
             agData.SetDeviceType(currStr);
        }
        
        std::getline(m_fName, currStr);
        sscanf(currStr.c_str(),"%s = %s", key, value);       
        if ( strcmp("room", key) == 0 )
        {
             currStr = value;
             agData.SetRoom(currStr);
        }
        
        std::getline(m_fName, currStr);
        sscanf(currStr.c_str(),"%s = %s", key, value);       
        if ( strcmp("floor", key) == 0 )
        {
             currStr = value;
             agData.SetFloor(currStr);
        }
        
        std::getline(m_fName, currStr);
        sscanf(currStr.c_str(),"%s = %s", key, value);       
        if ( strcmp("log", key) == 0 )
        {
             currStr = value;
             agData.SetLog(currStr);
        }
        
        std::getline(m_fName, currStr);
        sscanf(currStr.c_str(),"%s = %[^\n]s", key, value);       
        if ( strcmp("config", key) == 0 )
        {
             currStr = value;
             agData.SetConfig(currStr);
        }       
        m_agentsCfg.push(agData);
    }
    return m_agentsCfg;   
}




