/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Math.hpp"
#include "Camera.hpp"
#include "Transformable.hpp"

namespace Virtual
{
	/*Dynamic texture class*/
	class Texture
	{
	public:
		~Texture();
		void setTexture(SDL_Texture*);
		
		SDL_Texture* getTexture();
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
		bool isDrawing();
		
		/*Setters*/
		void setName	  (std::string);
		void setIsStatic  (bool);
		void setIsDrawing (bool);
	protected:	
		std::string name;
		bool is_static;
		bool is_drawing;
	};

	/*Simple image*/
	class Sprite
		:public Texture, public Drawable, public Transformable	
	{
	public:
		void draw(SDL_Renderer*, Camera&);
	};
	
	/*Single tile in a map*/
	class Tile
		:public Sprite
	{
		int tile;
	public:
		void setTile(int);
		int getTile();
	};
	
	/*"Storage" of map information*/
	struct Map
	{
		std::vector<std::vector<int>> numbers;
		std::vector<std::vector<std::shared_ptr<Tile>>> tiles;
		std::shared_ptr<Tile> getTileAt(Vector2<int>);
		
		Texture texture;
		
		std::string mapPath;
		std::string texturePath;
		int tilesSize;
		int maxNumber;
		int width;
		int height;
	};
}
