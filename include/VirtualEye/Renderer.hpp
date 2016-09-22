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
#include <fstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

#include "DebugLog.hpp"
#include "RenderUtils.hpp"

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
		void loadSprite(std::string, Vector2<int>, std::string, bool = false);
		
		/*Load map from iom file*/
		Vector2<int> loadMap(std::string);
		
		/*Returns dynamic pointer to map*/
		std::shared_ptr<Map> getMap();
		
		/*Returns reference to chosen element*/
		Sprite& getElementById(std::string);
	private:
		SDL_Renderer * renderer;
		std::shared_ptr<Camera> camera;
		std::shared_ptr<Map> map;
		
		std::vector<std::shared_ptr<Sprite>> spriteVector;
	};
}
