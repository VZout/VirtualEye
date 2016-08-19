CPP = src/sources
HPP = src/headers


CPPOBJS = $(CPP)/Device.cpp $(CPP)/EventManager.cpp 
HPPOBJS = $(HPP)/Device.hpp $(HPP)/EventManager.hpp 

LIBS = -lSDL2

run: $(HPPOBJS)$(CPPOBJS)
	g++ -w main.cpp $(HPPOBJS) $(CPPOBJS) -o run $(LIBS)

