/*  =============================================================*
 *   VirtualEye (c)			Dmitro Szewczuk		 				 *
 *   MIT License  http://choosealicense.com/licenses/mit/		 *
 *  =============================================================*/
 
#pragma once

#include <SDL2/SDL.h>

#include "Vector2.hpp"

namespace Virtual
{
	/*class gets control about object position on map*/
	class Camera
	{
	public:
		/*Gets window and level parametres*/
		void update(Vector2<int>, Vector2<int>);
			
		/*Get center of camera position*/
		void setCenter(Vector2<int>);
			
		/*This funciton move the center of camera*/
		void move(Vector2<int>);
			
		/*Returns rect to manipulate position in engine*/
		SDL_Rect getRect();
	private:
		SDL_Rect rect;
	};
}
