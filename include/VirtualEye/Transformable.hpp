/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include <SDL2/SDL.h>

#include "Math.hpp"

namespace Virtual
{
	#define FLIP(x) SDL_FLIP_##x

	/*!
	 *  \brief Class to manupulate position and size of object
	 */
	class Transformable
	{
	public:
		/*!
		 *	@return position of object 
		 */
		Vector2<int> getPosition();
		/*!
		 *	@return size of object 
		 */
		Vector2<int> getParametres();
		/*!
		 *	@return position of texture crop in object 
		 */
		Vector2<int> getCropPosition();
		/*!
		 *	@return size of texture crop in object 
		 */
		Vector2<int> getCropParametres();
		/*!
		 *	@return size of texture crop in object 
		 */
		Rectangle<int> getRectangle();
		/*!
		 *	@return angle of object 
		 */
		int getAngle();
		/*!
		 *	@return center of texture 
		 */
		Vector2<int> getCenter();
		/*!
		 *	\brief Setting position of object
		 * 	@param position - coords of position
		 */	
		void setPosition(Vector2<int> position);
		/*!
		 *	\brief Setting size of object
		 * 	@param size - coords of position
		 */	
		void setParametres(Vector2<int> size);
		/*!
		 *	\brief Setting position of crop of texture
		 * 
		 * 	@param cropPosition - coords of crop position(x and y)
		 */	
		void setCropPosition  (Vector2<int> cropPosition);
		/*!
		 *	\brief Setting position of crop of texture
		 * 
		 * 	@param cropSize - coords of crop position(width and height)
		 */	
		void setCropParametres(Vector2<int> cropSize);
		/*!
		 *	\brief Setting position and size of sprite
		 * 
		 * 	@param rect - coords of position and width and height
		 */	
		void setRectangle(Rectangle<int> rect);
		/*!
		 *	\brief Setting angle of sprite
		 * 
		 * 	@param angle - angle in degrees
		 */	
		void setAngle(int angle);
		/*!
		 *	\brief Setting flip of texture
		 * 
		 * 	@param flip - for exaple (FLIP(NONE))
		 */	
		void setFlip(SDL_RendererFlip flip);
		/*!
		 *	\brief Setting flip of texture
		 * 
		 * 	@param flip - for exaple (FLIP(NONE))
		 */	
		void move(Vector2<int> relativePosition, double delta);
		/*!
		 *	\brief Check is this Transformable collides with other
		 *
		 *	@return true or false
		 *  
		 * 	@param other - other Transformable object
		 */	
		bool isCollide(Transformable & other);
	protected:	
		SDL_Rect rect;
		SDL_Rect cropRect;
		SDL_RendererFlip flip;
		int angle;
	};
}
