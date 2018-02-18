

/** @file Loader.cpp
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include "Loader.h"
#include "AgentBuildData.h"
#include "IData_t.h"


#include <iostream>
#include <algorithm>
#include <dlfcn.h>  


Loader::Loader(std::string _soDir)
: m_soDir(_soDir)
, m_soHandles()
{
}

   
void Loader::CloseHandles (void* _handle)
{
    dlclose(_handle);
}

Loader::~Loader()
{   
   //for_each(m_soHandles.begin(), m_soHandles.end(), CloseHandles); 
    std::set<void*>::iterator it;  
    for (it = m_soHandles.begin(); it != m_soHandles.end(); ++it)
    {
           CloseHandles(*it);
    }
}



std::string Loader::GetFullPath(std::string _agType)   //_agType = "ambient_temp"    
{
	std::string fullPath(m_soDir);
	fullPath += _agType;            //fullPath = "./lib/ambient_temp"
	fullPath += ".so";              //fullPath = "./lib/ambient_temp.so"
	return fullPath;
}


shared_ptr<AgentBuildData> Loader::LoadSharedObject(std::string _soName)
{
    std::string fullPath = GetFullPath(_soName);
    void* handle = dlopen(fullPath.data(), RTLD_NOW);
    if (!handle)
    {
           std::cout << "Error open: %s" << dlerror() << std::endl;
    }
    m_soHandles.insert(handle);
     
    void* make = dlsym(handle,"MakeAgent");    
    if (!make)
    {
           std::cout << "Symbol MakeAgent not found: %s" << dlerror() << std::endl;
    }
    
    void* destr = dlsym(handle,"DestroyAgent");
    if (!destr)
    {
           std::cout << "Symbol DestroyAgent not found: %s" << dlerror() << std::endl;
    }
   
    shared_ptr<AgentBuildData> pAgentBuild(new AgentBuildData);
    
    pAgentBuild->SetAgentType(_soName);
    pAgentBuild->SetAgentMake(make);
    pAgentBuild->SetAgentDestroy(destr);
    
    return pAgentBuild;       
}    
    


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//#include <dirent.h>

//void OpenLibDir()
//{
//   DIR *libdir;
//   struct dirent *dent;
//   libdir = opendir("./lib/");   

//   if(NULL != libdir)
//   {
//        while((libdir=readdir(libdir))!=NULL)
//        {
//            if((strcmp(dent->d_name,".")==0 
//                || strcmp(dent->d_name,"..")==0 
//                || (*dent->d_name) == '.' ))
//            {   //do nothing
//            }
//            else
//            {
//                ?? = dent->d_name;
//            }
//        }
//    }
//    close(libdir);
//} 




    
        
