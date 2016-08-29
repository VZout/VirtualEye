/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include <SDL2/SDL.h>

#include "Vector2.hpp"
#include "Camera.hpp"

namespace Virtual
{
	class Texture
	{
	public:
		~Texture();
		void setTexture(SDL_Texture*);
		
		SDL_Texture& getTexture();
	protected:
		SDL_Texture * texture;	
	};
	
	/*With Drawable you can draw objects*/
	class Drawable
	{
	public:
		virtual void draw(SDL_Renderer*, Camera&) = 0;

		/*Getters*/
		std::string  getName();
		bool isStatic();
		
		/*Setters*/
		void setName	  (std::string);
		void setIsStatic  (bool);
	protected:	
		std::string name;
		bool is_static;
		
	};
	/*With Drawable you can manipulate position and parametres objects*/
	class Transformable
	{
	public:
		/*Getters*/
		Vector2<int> getPosition();
		Vector2<int> getParametres();
		Vector2<int> getCropPosition();
		Vector2<int> getCropParametres();

		/*Setters*/
		void setPosition(Vector2<int>);
		void setParametres(Vector2<int>);
		void setCropPosition  (Vector2<int>);
		void setCropParametres(Vector2<int>);

		/*Custom*/
		void move(Vector2<int>);
	protected:	
		SDL_Rect rect;
		SDL_Rect cropRect;
	};

	/*Simple image*/
	class Sprite
		:public Texture, public Drawable, public Transformable	
	{
	public:
		void draw(SDL_Renderer*, Camera&);
	};
	
	/*"Storage" of map information*/
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
