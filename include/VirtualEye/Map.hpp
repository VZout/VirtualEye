/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include "Math.hpp"
#include "DynamicPointers.hpp"

#include <vector>
#include <memory>
#include <string>

namespace Virtual
{
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
		std::shared_ptr<Tile> getTileAt(Vector2<int> position)
		{
			return tiles[position.x][position.y];
		}
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
