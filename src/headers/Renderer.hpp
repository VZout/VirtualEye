/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <iostream>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

#include "RenderUtils.hpp"
#include "Vector2.hpp"

namespace Virtual
{
	typedef std::shared_ptr<Sprite> sprite_ptr;

	/*This class control rendering buffers*/
 	class Renderer
	{
	public:
		Renderer(SDL_Window *);
		~Renderer(void);
	
		/*Funcion clear screen, rendering scene and swapped buffers*/
		void draw(Camera &);

		/*Deleting all sprites in vector*/
		void clearScene(void);

		/*Loads sprite into sprite vector*/
		void loadSprite(std::string, Vector2<int>, std::string);
		
		/*Returns reference to chosen element*/
		Sprite& getElementById(std::string);
	private:
		SDL_Renderer * renderer;
		Camera * camera;
		
		std::vector<sprite_ptr> vector;
	};
}
