#ifndef __ILOADER_H__
#define __ILOADER_H__


/** @file ILoader.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs (yet).
 */

#include <string>
#include <tr1/memory>
using std::tr1::shared_ptr;

class AgentBuildData;

class ILoader
{
public:
    ILoader() {}
    ILoader(std::string _soDir);
          
    virtual ~ILoader() {}
    
	virtual shared_ptr<AgentBuildData> LoadSharedObject(std::string _soName) = 0;
private:
};

#endif /*__ILOADER_H__*/
