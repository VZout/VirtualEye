CPP = src/sources
HPP = src/headers

CPPOBJS = $(CPP)/Device.cpp $(CPP)/EventManager.cpp $(CPP)/Renderer.cpp 
HPPOBJS = $(HPP)/Device.hpp $(HPP)/EventManager.hpp $(HPP)/Renderer.hpp 

LIBS = -lSDL2

run: $(HPPOBJS)$(CPPOBJS)
	g++ -w main.cpp $(HPPOBJS) $(CPPOBJS) -o run $(LIBS)

