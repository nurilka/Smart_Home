
# Agents makefile - SO only, no versions
.PHONY: clean 

# compulsory flags
CXX = clang++
CXXFLAGS = -g -ansi -pedantic -Wall -Werror -fPIC -ansi


# local defs
CXXFLAGS += -std=c++03 -Weffc++ 


OBJS =  $(AGNAME).o ../InputDataContainer.o ../IAgent_t.o ../Event_t.o 

#DYNAMICLIB: dynamic link - soft link to actual library for use in programms

#path and lib name
LIBPATH = ../lib
DYNAMICLIB = $(AGNAME).so
MOVETOLIB = mv $(DYNAMICLIB) $(LIBPATH)

#flags for shared lib
LIBFLAGS = -shared
	
lib : $(DYNAMICLIB)
	@$(MOVETOLIB)

	
$(DYNAMICLIB): $(OBJS)
	$(CXX) -fPIC $(LIBFLAGS) -o $(DYNAMICLIB) $(OBJS)
	

include depends

depends:
	$(CXX) -MM $(CXXFLAGS) -c $(OBJS:.o=.cpp) > depends

clean:
	rm -f depends
	rm -f $(OBJS)




	

