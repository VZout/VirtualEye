/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>

#include "Vector2.hpp"
#include "Camera.hpp"

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
	};
	
	/*With Drawable you can manipulate position and parametres and draw objects*/
	class Drawable
	{
	public:
		virtual void draw(SDL_Renderer*, Camera&) = 0;

		/*Getters*/
		Vector2<int> getPosition();
		Vector2<int> getParametres();
		std::string  getName();
		bool getIsStatic();
		
		/*Setters*/
		void setPosition  (Vector2<int>);
		void setParametres(Vector2<int>);
		void setName	  (std::string);
		void setIsStatic  (bool);

		/*Custom*/
		void move(Vector2<int>);
	protected:	
		SDL_Rect rect;
		std::string name;
		bool is_static;
		
	};

	class Sprite
		:public Texture, public Drawable	
	{
	public:
		void draw(SDL_Renderer*, Camera&);
	};
	
	struct Map
	{
		std::vector<std::string> mapString;
		std::string mapPath;
		std::string texturePath;
		int tilesSize;
		int maxNumber;
		int width;
		int height;
	};
}
