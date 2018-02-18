#ifndef __SERVER_H__
#define __SERVER_H__


/** @file Server.h
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include <string>

#include "Initializer.h"
#include "AgentsContainer.h"

class Server
{
public:
    
    Server();  
    ~Server();      

    void Run(std::string _soDir, std::string _configFile);

    //debug
    AgentsContainer* GetAgentsContainer() const;


private:
    Initializer m_init;
    
	Server(const Server& _other); 
    Server& operator= (const Server& _other);
    
};

#endif /* __SERVER_H__ */





