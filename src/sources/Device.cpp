/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#include "../headers/Device.hpp"

namespace Virtual
{
	Device::Device(int width, int height)
	{
		this->width = width;
		this->height = height;
		
		SDL_Init(SDL_INIT_EVERYTHING);
	
		window = SDL_CreateWindow("VirtualEye | SDL2 Renderer",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		if(!window)
			std::cout << "VirtualEye new log: Window creation failed!" << std::endl;

		eventManager = new EventManager();
		renderer = new Renderer(window);
		camera = new Camera();
	}
	//Start game loop
	void Device::start()
	{
		onInit();
		while(!eventManager->isClosed())
		{
			camera->update(Vector2<int>(width, height), levelProperties);
			eventManager->pollEvents();
			renderer->draw(*camera);

			onUpdate();
		}
	}
	Device::~Device(void)
	{
		//Deleting handles
		delete eventManager;
		delete renderer;

		SDL_DestroyWindow(window);
	}
}
