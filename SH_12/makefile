
# Smart_Home makefile
.PHONY: clean 
# compulsory flags
CXX = clang++
CXXFLAGS = -g -ansi -pedantic -Wall -Werror -fPIC


# local defs
CXXFLAGS += -std=c++03 -Weffc++
LINKERFLAGS = -ldl
#CFLAGS += -I$(INCDIR) #ambient_temp.o 
OBJS = test_SH.o EventGenerator.o Event_t.o InputDataContainer.o IAgent_t.o SubsManager.o \
       Router.o AgentsFactory.o AgentsContainer.o Configurator.o Loader.o SoRegistry.o \
       Initializer.o Server.o


test_SH : $(OBJS)
	$(CXX) $(CXXFLAGS) -o test_SH $(OBJS:.o=.cpp) $(LINKERFLAGS)
	
include depends

depends:
	$(CXX) -MM -c $(OBJS:.o=.cpp) > depends

clean:
	rm -f depends
	rm -f $(OBJS)
	rm -f test_SH



	

