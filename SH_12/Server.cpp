
/** @file Server.cpp
 *  @brief 
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include "Server.h"

Server::Server()
: m_init()
{
}
  
Server::~Server()
{   //do nothing
}      

void Server::Run(std::string _soDir, std::string _configFile)
{
    m_init.InitializeAndRun(_soDir, _configFile);
}

AgentsContainer* Server::GetAgentsContainer() const
{
    return m_init.GetAgentsContainer();
}





