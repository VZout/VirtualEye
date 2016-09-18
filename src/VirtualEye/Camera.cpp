/*  =============================================================*
 *   VirtualEye (c)			Dmitro Szewczuk		 				 *
 *   MIT License  http://choosealicense.com/licenses/mit/		 *
 *  =============================================================*/
 
#include "../../include/VirtualEye/Camera.hpp"

namespace Virtual
{	
	void Camera::update(Vector2<int> window, Vector2<int> level)
	{
		//Setting camera properties
		rect.w = window.x;
		rect.h = window.y;
		
		//Camera blocking
		if(rect.x < 0)
			rect.x = 0;
		if(rect.y < 0)
			rect.y = 0;
		if(rect.x > level.x - rect.w)
			rect.x = level.x - rect.w;
		if(rect.y > level.y - rect.h)
			rect.y = level.y - rect.h;
	}
	void Camera::setCenter(Vector2<int> center)
	{
		//Setting camera position
		rect.x = center.x - rect.w / 2;
		rect.y = center.y - rect.h / 2;
	}
	void Camera::move(Vector2<int> relativePosition)
	{
		rect.x += relativePosition.x;
		rect.y += relativePosition.y;
	}
	SDL_Rect Camera::getRect()
	{
		return rect;
	}
}
