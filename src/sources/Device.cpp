#include "Device.hpp"

Device::Device(int width, int height)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Vistula | SDL2 Renderer", SDL_WINDOWPOS_CENTRED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
}
