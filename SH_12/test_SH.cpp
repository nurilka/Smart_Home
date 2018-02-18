
/** @file test_SH.cpp
 *  @brief 
 *  pass arguments 
 *  soDir = *argv[0];
 *  cnfgFile = *argv[1]
 *
 *  @author Nurit (H-45)
 *
 *  @bug No known bugs.
 */


#include <string>
#include "Server.h"

#include "./Agents/ambient_temp.h"


int main(int argc, char* argv[])
{
    
    std::string soDir("./lib/");
    std::string cnfgFile("config.ini");

    Server server;
    server.Run(soDir, cnfgFile);

    ambient_temp* a1 = (ambient_temp*)server.GetAgentsContainer()->GetAgent("Temprature-1-a");
    a1->SendReading();
    
   
    return 0;
}
