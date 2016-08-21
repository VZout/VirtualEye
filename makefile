CPP = src/sources
HPP = src/headers

CPPOBJS = $(CPP)/Device.cpp $(CPP)/EventManager.cpp $(CPP)/Renderer.cpp $(CPP)/RenderUtils.cpp
HPPOBJS = $(HPP)/Device.hpp $(HPP)/EventManager.hpp $(HPP)/Renderer.hpp $(HPP)/RenderUtils.hpp $(HPP)/Vector2.hpp

LIBS = -lSDL2

run: $(HPPOBJS) $(CPPOBJS)
	g++ -w main.cpp $(HPPOBJS) $(CPPOBJS) -o run $(LIBS)
