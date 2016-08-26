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
		
		for(auto &i : vector)
			i->draw(renderer);
			
		SDL_RenderPresent(renderer);
	}
	void Renderer::loadSprite(std::string path, Vector2<int> position, std::string name)
	{
		Sprite * s = new Sprite;
		
		//Texture & position pushing
        SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
		s->setTexture(texture);
		s->setPosition(position);
		s->setName(name);
		
		//Detect of Width and Height
		Vector2<int> * par = new Vector2<int>;
		SDL_QueryTexture(&s->getTexture(), NULL, NULL, &par->x, &par->y);
		s->setParametres(*par);

		vector.push_back(s);
	}
	Sprite& Renderer::getElementById(std::string name)
	{
		for(auto &i : vector)
		{
			if(i->getName() == name)
				return *i;
		}
	}
}	
