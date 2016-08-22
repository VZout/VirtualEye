/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <vector>
#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h> 

#include "RenderUtils.hpp"
#include "Vector2.hpp"

namespace Virtual
{
	/*This class control rendering buffers*/
 	class Renderer
	{
	public:
		Renderer(SDL_Window *);
		~Renderer(void);
	
		/*Funcion clear screen, rendering scene and swapped buffers*/
		void draw();

		void loadSprite(std::string, Vector2<int>);
	private:
		SDL_Renderer * renderer;
		
		std::vector<Sprite*> vector;
	};
}
