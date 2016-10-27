/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <fstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

#include "DebugLog.hpp"
#include "RenderUtils.hpp"
#include "Map.hpp"

namespace Virtual
{
	typedef std::shared_ptr<Sprite> sprite_ptr;

	/*! \brief Management of current scene.
	 *
	 *  Class of renderer manage the scene by loading sprite, label to they, cleaning the scene etc.
	 */
 	class Renderer
	{
	public:
		Renderer(SDL_Window *);
		~Renderer(void);
		/*! \brief Draws the scene.
		 * 
		 * 	@param camera the reference to camera object
		 *
		 *  Draws the scene on the screen.
		 */
		void draw(Camera & camera);
		/*! \brief Clearing the scene.
		 * 
		 *  Deleting all vector and cleaning them. Nothing will not rendering after that.
		 */
		void clearScene(void);
		/*! \brief Loading sprite.
		 * 
		 *  @param path -			path to image
		 * 	@param position	-		integer vector of the position relative to window
		 * 	@param name -			identity name of sprite
		 * 	@param isDisplaying -	fact is the object was displaying
		 * 
		 *  Loading sprite, setting position and name of they and pushing the instance into sprite vector.
		 */
		void loadSprite(std::string path, Vector2<int> position, std::string name, bool isDisplaying = false);
		/*! \brief Loading sprite.
		 * 
		 *  @param path	-			path to font
		 * 	@param text	-			text on label
		 * 	@param position -		integer vector of the position relative to window
		 * 	@param name - 			identity name of sprite
		 * 	@param color - 			color of text in label
		 * 	@param size -			size of font
		 * 	@param isDisplaying - 	fact is the object was displaying
		 * 
		 *  Creating label, setting position and name of they and pushing the instance into label vector.
		 */
		void loadLabel(std::string path, std::string text, Vector2<int> position, std::string name, Color color, int size = 30, bool isDisplaying = false);
		/*! \brief Loads map.
		 * 
		 *	@return Integer vector of width and height of map in pixels
		 * 
		 * 	@param path - path to map init file (*.iom)
		 *
		 *  Create map instance, loades tiles and pushing then into vector.
		 */
		Vector2<int> loadMap(std::string path);
		/*!
		 * 	@return Dynamic pointer into map info
		 *
		 *  Returning map info like width and height, number of tiles etc.
		 */
		std::shared_ptr<Map> getMap(void);
		/*!
		 * 	@return The object of sprite by the name
		 * 
		 * 	@param name - name of searched sprite
		 */
		Sprite& getSpriteById(std::string name);
		/*!
		 *  @return The object of label by the name
		 * 
		 * 	@param name - name of searched label
		 */
		Label& getLabelById(std::string name);
	private:
		SDL_Renderer * renderer;
		std::shared_ptr<Camera> camera;
		std::shared_ptr<Map> map;
		
		std::vector<std::shared_ptr<Sprite>> spriteVector;
		std::vector<std::shared_ptr<Label>> labelVector;
	};
}
