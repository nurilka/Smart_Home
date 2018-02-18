#ifndef __LOADER_H__
#define __LOADER_H__


/** @file Loader.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs (yet).
 */

#include "ILoader.h"
#include <string>
#include <set>
#include <tr1/memory>
using std::tr1::shared_ptr;



class AgentBuildData;

class Loader: public ILoader
{
public:
    Loader(std::string _soDir);    
    ~Loader();
    
	virtual shared_ptr<AgentBuildData> LoadSharedObject(std::string _soName);
	

private:
    std::string m_soDir;
    std::set<void*> m_soHandles;
    
    void CloseHandles (void* _handle);
    std::string GetFullPath(std::string _agType);   //_agType = "ambient_temp"
       
    Loader(const Loader& _other); 
    Loader& operator=(const Loader& _other);
};

#endif /*__LOADER_H__*/
