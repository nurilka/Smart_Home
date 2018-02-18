#ifndef __AGENT_BUILD_DATA_H__
#define __AGENT_BUILD_DATA_H__


/** @file AgentBuildData.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include <string>


class AgentBuildData
{
public:
   
    AgentBuildData()
    : m_agentType()
    , m_makePtr(0)
    , m_destroyPtr(0)
    {   //do nothing
    }  
    virtual ~AgentBuildData() { }      

    virtual std::string GetAgentType() const { return m_agentType; }
    virtual void* GetAgentMake() const { return m_makePtr; }
    virtual void* GetAgentDestroy() const { return m_destroyPtr; }
    
    void SetAgentType(std::string _agType) { m_agentType = _agType; }
    void SetAgentMake(void* _make)  { m_makePtr = _make; }
    void SetAgentDestroy(void* _destroy) { m_destroyPtr = _destroy; }
    

private:
    std::string m_agentType;
    void* m_makePtr;
    void* m_destroyPtr;

	AgentBuildData(const AgentBuildData& _other); 
    AgentBuildData& operator= (const AgentBuildData& _other);
    
};

#endif /* __AGENT_BUILD_DATA_H__ */








