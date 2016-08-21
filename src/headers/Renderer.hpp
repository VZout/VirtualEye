/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <iostream>
#include <SDL2/SDL.h>

namespace Virtual
{
	/*This class control rendering buffers*/
 	class Renderer
	{
	public:
		Renderer(SDL_Window * window);
		~Renderer(void);
	
		/*Funcion clear screen, rendering scene and swapped buffers*/
		void draw(); //TODO SCENE RENDERING
	private:
		SDL_Renderer * renderer;
	};
 }
