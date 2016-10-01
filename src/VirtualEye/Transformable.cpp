/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../../include/VirtualEye/Transformable.hpp"

namespace Virtual
{
	/*Transformable*/
	void Transformable::setPosition(Vector2<int> position)
	{
		rect.x = position.x;
		rect.y = position.y;
	}
	void Transformable::setParametres(Vector2<int> parametres)
	{
		rect.w = parametres.x;
		rect.h = parametres.y;
	}
	void Transformable::setCropPosition(Vector2<int> position)
	{
		cropRect.x = position.x;
		cropRect.y = position.y;
	}
	void Transformable::setCropParametres(Vector2<int> parametres)
	{
		cropRect.w = parametres.x;
		cropRect.h = parametres.y;
	}
	
	
	void Transformable::setRectangle(Rectangle<int> rectangle)
	{
		rect.x = rectangle.x;
		rect.y = rectangle.y;
		rect.w = rectangle.w;
		rect.h = rectangle.h;
	}
	
	
	void Transformable::setAngle(int angle)
	{
		this->angle = angle;
	}
	
	
	Vector2<int> Transformable::getPosition()
	{
		return Vector2<int>(rect.x, rect.y);
	}
	Vector2<int> Transformable::getParametres()
	{
		return Vector2<int>(rect.w, rect.h);
	}
	
	Vector2<int> Transformable::getCropPosition()
	{
		return Vector2<int>(cropRect.x, cropRect.y);
	}
	Vector2<int> Transformable::getCropParametres()
	{
		return Vector2<int>(cropRect.w, cropRect.h);
	}
	
	Vector2<int> Transformable::getCenter()
	{
		return Vector2<int>(rect.x - rect.w / 2, rect.y - rect.h / 2);
	}
	
	void Transformable::move(Vector2<int> relativePosition, double deltaTime)
	{
		rect.x += relativePosition.x * deltaTime;
		rect.y += relativePosition.y * deltaTime;
	}
	Rectangle<int> Transformable::getRectangle()
	{
		return {rect.x, rect.y, rect.w, rect.h};
	}
	
	
	int Transformable::getAngle()
	{
		return angle;
	}
	
	void Transformable::setFlip(SDL_RendererFlip flip)
	{
		this->flip = flip;
	}
	bool Transformable::isCollide(Transformable &other)
	{
			if(rect.x < other.getPosition().x + other.getParametres().x && rect.x + rect.w > other.getPosition().x && 
			rect.y < other.getPosition().y + other.getParametres().y && rect.y + rect.h > other.getPosition().y)
				return true;
			else 
				return false;
	}
}
