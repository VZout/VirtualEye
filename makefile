CPP = src/sources
HPP = src/headers

CPPOBJS = $(CPP)/Device.cpp $(CPP)/EventManager.cpp $(CPP)/Renderer.cpp $(CPP)/RenderUtils.cpp $(CPP)/Camera.cpp
HPPOBJS = $(HPP)/Device.hpp $(HPP)/EventManager.hpp $(HPP)/Renderer.hpp $(HPP)/RenderUtils.hpp $(HPP)/Camera.hpp $(HPP)/Vector2.hpp

LIBS = -lSDL2 -lSDL2_image

run: $(HPPOBJS) $(CPPOBJS)
	g++ -w main.cpp $(HPPOBJS) $(CPPOBJS) -o run $(LIBS)
