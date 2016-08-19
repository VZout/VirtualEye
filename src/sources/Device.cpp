/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#include "Device.hpp"

Device::Device(int width, int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	window = SDL_CreateWindow("VirtualEye | SDL2 Renderer",width, height, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_SHOWN);
	
	onInit();
	while(true)
	{
		onUpdate();
	}
}
