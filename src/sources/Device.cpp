/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#include "../headers/Device.hpp"

namespace Virtual
{
	Device::Device(int width, int height)
	{
		SDL_Init(SDL_INIT_EVERYTHING);
	
		window = SDL_CreateWindow("VirtualEye | SDL2 Renderer",width, height, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_SHOWN);
		
		eventManager = new EventManager();
		renderer = new Renderer(window);

		onInit();
		while(!eventManager->isClosed())
		{
			eventManager->pollEvents();
			renderer->draw();

			onUpdate();
		}
	}
	Device::~Device(void)
	{

	}
}
