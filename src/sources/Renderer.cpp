/* =============================================================*
 *  VirtualEye (c)         Dmitro Szewczuk                      *
 *  MIT License  http://choosealicense.com/licenses/mit         *
 * =============================================================*/ 

#include "../headers/Renderer.hpp"

namespace Virtual
{
	Renderer::Renderer(SDL_Window * window)
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}
	Renderer::~Renderer(void)
	{
		SDL_DestroyRenderer(renderer);
	}
	void Renderer::draw()
	{
		SDL_SetRenderDrawColor(renderer, 125, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
}	
