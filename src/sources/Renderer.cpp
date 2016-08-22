/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../headers/Renderer.hpp"

namespace Virtual
{
	Renderer::Renderer(SDL_Window * window)
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if(!renderer)
			std::cout << "VirtualEye new log: Renderer creation failed!" << std::endl;
	}
	Renderer::~Renderer(void)
	{
		SDL_DestroyRenderer(renderer);
	}
	void Renderer::draw()
	{
		SDL_SetRenderDrawColor(renderer, 125, 0, 255, 255);
		SDL_RenderClear(renderer);
		
		//TODO: MEMORY LEAK 
		/*for(auto &i : vector)
			i->draw(renderer);*/
		SDL_RenderPresent(renderer);
	}
	void Renderer::loadSprite(std::string path, Vector2<int> position)
	{
#include <iostream>
		Sprite * s = new Sprite;
		s->texture = IMG_LoadTexture(renderer, path.c_str());
		s->setPosition(position);
		
		Vector2<int> * pos = new Vector2<int>;
		SDL_QueryTexture(&s->getTexture(), NULL, NULL, &pos->x, &pos->y);
		std::cout << "a" << std::endl;
		vector.push_back(s);

		delete s;
		delete pos;
	}
}	
