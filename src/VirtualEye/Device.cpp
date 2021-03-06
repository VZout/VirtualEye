/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#include "../../include/VirtualEye/Device.hpp"

namespace Virtual
{
	Device::Device(int width, int height)
	{
		this->width = width;
		this->height = height;
		
		//Lua opening
		state = luaL_newstate();
		luaL_openlibs(state);
		Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG);
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		
		//SDL opening
		SDL_Init(SDL_INIT_EVERYTHING);
		TTF_Init();
	
		window = SDL_CreateWindow("VirtualEye | SDL2 Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		if(!window)
			DebugLog::getInstance().addToLog("VirtualEye new log: Window creation failed!");

		//Subdevices of engine
		eventManager = std::shared_ptr<EventManager>(new EventManager);
		renderer = std::shared_ptr<Renderer>(new Renderer(window));
		camera = std::shared_ptr<Camera>(new Camera);
		clock = std::shared_ptr<Clock>(new Clock);
		
		//Setting camera and level
		camera->setCenter(Vector2<int>(0, 0));
		levelProperties = Vector2<int>(width, height);
	}
	//Start game loop
	int Device::start(std::string file)
	{
		luaL_loadfile(state, file.c_str());
				
		lua_pcall(state, 0, LUA_MULTRET, 0);
		
		onInit();
		DebugLog::getInstance().printLog();
		while(!eventManager->isClosed())
		{
			clock->start();
			clock->stop();
			eventManager->pollEvents();
			camera->update(Vector2<int>(width, height), levelProperties);
			renderer->draw(*camera);

			onUpdate();
		}
		
		SDL_DestroyWindow(window);
		lua_close(state);
		
		return 0;
	}
	void Device::setParametres(Vector2<int> parametres)
	{
		SDL_SetWindowSize(window, parametres.x, parametres.y);
	}
	void Device::setFullScreened(bool is)
	{
		if(is == true)
			SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	}
	Device::~Device(void)
	{
		SDL_DestroyWindow(window);
	}
}
