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

		eventManager = std::shared_ptr<EventManager>(new EventManager);
		renderer = std::shared_ptr<Renderer>(new Renderer(window));
		camera = std::shared_ptr<Camera>(new Camera);
		
		camera->setCenter(Vector2<int>(0, 0));
		levelProperties = Vector2<int>(width, height);
	}
	//Start game loop
	int Device::start()
	{
		onInit();
		while(!eventManager->isClosed())
		{
			eventManager->pollEvents();
			camera->update(Vector2<int>(width, height), levelProperties);
			renderer->draw(*camera);

			onUpdate();
		}
		
		return 0;
	}
	Device::~Device(void)
	{
		SDL_DestroyWindow(window);
	}
}
