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
	
	/*Dynamic font class*/
	class Font
	{
	public:
		~Font();		
		void setFont(TTF_Font*);

		TTF_Font* getFont();
	protected:
		TTF_Font* font;
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
	/*With Drawable you can manipulate position and parametres objects*/
	class Transformable
	{
	public:
		/*Getters*/
		Vector2<int> getPosition();
		Vector2<int> getParametres();
		Vector2<int> getCropPosition();
		Vector2<int> getCropParametres();
		Rectangle<int> getRectangle();
		
		Vector2<int> getCenter();

		/*Setters*/
		void setPosition(Vector2<int>);
		void setParametres(Vector2<int>);
		void setCropPosition  (Vector2<int>);
		void setCropParametres(Vector2<int>);
		void setRectangle(Rectangle<int>);

		/*Custom*/
		void move(Vector2<int>);
		bool isCollide(Transformable &);
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
	
	/*Single tile in a map*/
	class Tile
		:public Sprite
	{
		int tile;
	public:
		void setTile(int);
		int getTile();
	};
	
	/*Single label*/
	class Label
		:public Sprite, public Font
	{
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
