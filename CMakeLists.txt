cmake_minimum_required(VERSION 2.8.9)
project (VirtualEye)

set(hpp include/VirtualEye)
set(cpp src/VirtualEye)

set(hppfiles ${hpp}/Camera.hpp ${hpp}/Clock.hpp ${hpp}/DebugLog.hpp ${hpp}/Device.hpp ${hpp}/EventManager.hpp ${hpp}/Renderer.hpp ${hpp}/RenderUtils.hpp ${hpp}/Transformable.hpp ${hpp}/Math.hpp )
set(cppfiles ${cpp}/Camera.cpp ${cpp}/Clock.cpp ${cpp}/DebugLog.cpp ${cpp}/Device.cpp ${cpp}/EventManager.cpp ${cpp}/Renderer.cpp ${cpp}/RenderUtils.cpp ${cpp}/Transformable.cpp)

set(pro Pong)
set(testpro tests/${pro}/main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY tests/${pro}/)

add_executable(VirtualEye ${testpro} ${hppfiles} ${cppfiles})

target_link_libraries(VirtualEye -lSDL2 -lSDL2_image -llua)
