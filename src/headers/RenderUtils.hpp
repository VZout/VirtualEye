/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Vector2.hpp"

namespace Virtual
{
	class Renderer;
	class Texture
	{
	public:
		~Texture();
		void setTexture(SDL_Texture*);
		
		SDL_Texture& getTexture();
	protected:
		SDL_Texture * texture;	
	friend class Renderer;
	};
	
	/*With Drawable you can manipulate position and parametres and draw objects*/
	class Drawable
	{
	public:
		virtual void draw(SDL_Renderer*) = 0;

		/*Getters*/
		Vector2<int> getPosition();
		Vector2<int> getParametres();
		std::string  getName();
		
		/*Setters*/
		void setPosition  (Vector2<int>);
		void setParametres(Vector2<int>);
		void setName	  (std::string);

		/*Custom*/
		void move(Vector2<int>);
		
	protected:	
		SDL_Rect rect;
		std::string name;
		
	};

	class Sprite
		:public Texture, public Drawable	
	{
	public:
		void draw(SDL_Renderer*);
	};
}
