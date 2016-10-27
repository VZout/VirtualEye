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
#include "MusicPlayer.hpp"

namespace Virtual
{
	/*!
	 *  \brief Class able to drawing by engine
	 */
	class Drawable
	{
	public:
		/*!
		 *  \brief Function that use engine to draw object
		 * 
		 * 	@param renderer - pointer into SDL_Renderer
		 *  @param camera - reference to camera in engine
		 */
		virtual void draw(SDL_Renderer* renderer, Camera& camera) = 0;
		/*!
		 * 	@return true if the object was static(doesn't move by camera) / false if it isn't
		 */
		bool isStatic();
		/*!
		 * 	@return true if the object was able to drawing / false if it isn't
		 */
		bool isDrawing();
		/*!
		 *  \brief Sets fact is the object able to be static(don't move by camera)
		 * 
		 * 	@param is - fact is the object was static
		 */
		void setIsStatic  (bool is);
		/*!
		 *  \brief Sets fact is the object able to drawing by engine
		 * 	
		 * 	@param is - fact is the object was able to drawing
		 */
		void setIsDrawing (bool is);
	protected:	
		bool is_static;
		bool is_drawing;
	};

	/*!
	 *  \brief Simple sprite class, like Label
	 */
	class Sprite
		:public Texture, public Drawable, public Transformable, public NameObject
	{
	public:
		/*!
		 *  \brief Function that use engine to draw object
		 * 
		 * 	@param renderer - pointer into SDL_Renderer
		 *  @param camera - reference to camera in engine
		 */
		void draw(SDL_Renderer* renderer, Camera& camera);
	};
	
	/*!
	 *  \brief Simple tile class
	 */
	class Tile
		:public Texture, public Drawable, public Transformable, public NameObject
	{
		int tile;
	public:
		/*!
		 *  \brief Function that use engine to draw object
		 * 
		 * 	@param renderer - pointer into SDL_Renderer
		 *  @param camera - reference to camera in engine
		 */
		void draw(SDL_Renderer * renderer, Camera & camera);
		/*!
		 *  \brief Sets tile type number
		 * 
		 * 	@param type - number of type
		 */
		void setTile(int type);
		/*!
		 * 	@return integer tile type number
		 */
		int getTile();
	};
	/*!
	 *  \brief Simple sprite dynamic class, like Sprite
	 */
	class Label
		:public Texture, public Drawable, public Transformable, public NameObject
	{
	public:
		/*!
		 *  \brief Function that use engine to draw object
		 * 
		 * 	@param renderer - pointer into SDL_Renderer
		 *  @param camera - reference to camera in engine
		 */
		void draw(SDL_Renderer * renderer, Camera & camera);
		/*!
		 *  \brief Setting font color
		 * 
		 * 	@param color - RGB Color structure
		 */
		void setColor(Color color);
		/*!
		 *  \brief Setting Font into Label
		 * 
		 * 	@param font - Dynamic pointer into Font
		 */
		void setFont(std::shared_ptr<Font> font);
		/*!
		 *  \brief Setting Font size
		 * 
		 * 	@param size - integer number
		 */
		void setSize(int size);
		/*!
		 * 	@param text - string to drawing
		 */
		void setText(std::string text);
	private:
		std::string text;
		std::shared_ptr<Font> font;
		Color color;
		int size;
		bool isChanged = false;
	};
	
	/*!
	 *  \brief Info about map
	 */
	struct Map
	{
		/*!
		 *  \brief Numbers type of one single tile
		 */
		std::vector<std::vector<int>> numbers;
		/*!
		 *  \brief Storage of all tiles of map
		 */
		std::vector<std::vector<std::shared_ptr<Tile>>> tiles;
		/*!
		 *  \brief Numbers type of one single tile
		 * 
		 * 	@param position - position of sprite in the table (like Vector2<int>(2, 2) to get the tile at 2:2 coords)
		 * 
		 *	@return Reference to tile by they position in table
		 */
		std::shared_ptr<Tile> getTileAt(Vector2<int> position);
		/*!
		 *  \brief Tileset texture
		 */
		Texture texture;
		/*!
		 *  \brief Path to map definition (*.iom)
		 */
		std::string mapPath;
		/*!
		 *  \brief Path to tilset
		 */
		std::string texturePath;
		/*!
		 *  \brief Width and height of one tile
		 */
		int tilesSize;
		/*!
		 *  \brief The biggest number of tile type
		 */
		int maxNumber;
		/*!
		 *  \brief Width of map in pixel
		 */
		int width;
		/*!
		 *  \brief Height of map in pixel
		 */
		int height;
	};
}
