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
		void draw(void);

		/*Deleting all sprites in vector*/
		void clearScene(void);

		/*Loads sprite into sprite vector*/
		void loadSprite(std::string, Vector2<int>, std::string);
		
		/*Returns reference to chosen element*/
		Sprite& getElementById(std::string);
	private:
		SDL_Renderer * renderer;
		
		std::vector<Sprite*> vector;
	};
}
