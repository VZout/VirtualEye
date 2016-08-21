/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../headers/RenderUtils.hpp"

namespace Virtual
{
	Vector2<int> Drawable::getPosition()
	{
		return Vector2<int>(rect.x, rect.y);
	}
	Vector2<int> Drawable::getParametres()
	{
		return Vector2<int>(rect.w, rect.h);
	}
	void Drawable::setPosition(Vector2<int> position)
	{
		rect.x = position.x;
		rect.y = position.y;
	}
	void Drawable::setParametres(Vector2<int> parametres)
	{
		rect.w = parametres.x;
		rect.h = parametres.y;
	}
}
