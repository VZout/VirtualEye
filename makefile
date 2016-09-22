CPP = src/VirtualEye
HPP = include/VirtualEye
 
CPPOBJS = $(CPP)/Device.cpp $(CPP)/EventManager.cpp $(CPP)/Renderer.cpp $(CPP)/RenderUtils.cpp $(CPP)/Camera.cpp
HPPOBJS = $(HPP)/Device.hpp $(HPP)/EventManager.hpp $(HPP)/Renderer.hpp $(HPP)/RenderUtils.hpp $(HPP)/Camera.hpp $(HPP)/Math.hpp

LIBS = -lSDL2 -lSDL2_image

run: $(HPPOBJS) $(CPPOBJS)
	g++ -w tests/RPG/main.cpp $(HPPOBJS) $(CPPOBJS) -o tests/RPG/run $(LIBS)
	
