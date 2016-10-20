/*  =============================================================*
 *   VirtualEye (c)			Dmitro Szewczuk		 				 *
 *   MIT License  http://choosealicense.com/licenses/mit/		 *
 *  =============================================================*/
 
#pragma once

#include <SDL2/SDL.h>

#include "Math.hpp"

namespace Virtual
{
	/*!
	 *  \brief Just camera.
	 */
	class Camera
	{
	public:
		/*!
		 *  \brief Updates the info about resolution of window and level
		 * 
		 * 	@param windowResolution - Integer vectors of resolution of window
		 * 	@param levelResolution - Integer vectors of resolution of map
		 */
		void update(Vector2<int> windowResolution, Vector2<int> levelResolution);	
		/*!
		 *  \brief Updates position of camera
		 * 
		 * 	@param centerPosition - Integer vector of center of camera
		 */
		void setCenter(Vector2<int> centerPosition);
		/*!
		 *  \brief Move the camera relativly of previous position
		 * 
		 * 	@param relativePosition - Integer vector of changed position
		 */
		void move(Vector2<int> relativePosition);
		/*!
		 * 	@return SDL rectangle of position and resolution of camera
		 */
		SDL_Rect getRect();
	private:
		SDL_Rect rect;
	};
}
