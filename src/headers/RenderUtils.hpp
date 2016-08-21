/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <SDL2/SDL.h>

#include "Vector2.hpp"

namespace Virtual
{
	class Texture
	{
	protected:
		SDL_Texture * texture;	
	};
	
	/*With Drawable you can manipulate position and parametres and draw objects*/
	class Drawable
	{
	public:
		virtual void draw() = 0;

		/*Getters*/
		Vector2<int> getPosition();
		Vector2<int> getParametres();
		
		/*Setters*/
		void setPosition(Vector2<int> position);
		void setParametres(Vector2<int> parametres);

	protected:	
		SDL_Rect rect;
	};
}
