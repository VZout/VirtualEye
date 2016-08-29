/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../headers/RenderUtils.hpp"

namespace Virtual
{
	/*Texture*/
	Texture::~Texture()
	{
		SDL_DestroyTexture(texture);
	}
	void Texture::setTexture(SDL_Texture * texture)
	{
		this->texture = texture;
	}
	SDL_Texture & Texture::getTexture()
	{
		return *texture;
	}

	/*Drawable*/
	std::string	Drawable::getName()
	{
		return name;
	}
	bool Drawable::isStatic()
	{
		return is_static;
	}
	
	void Drawable::setName(std::string name)
	{
		this->name = name;
	}
	void Drawable::setIsStatic(bool is)
	{
		is_static = is;
	}
	
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
	
	Vector2<int> Transformable::getPosition()
	{
		return Vector2<int>(rect.x, rect.y);
	}
	Vector2<int> Transformable::getParametres()
	{
		return Vector2<int>(rect.w, rect.h);
	}
	
	void Transformable::move(Vector2<int> relativePosition)
	{
		rect.x += relativePosition.x;
		rect.y += relativePosition.y;
	}
	/*Sprite*/
	void Sprite::draw(SDL_Renderer * renderer, Camera& camera)
	{
		if(!is_static)
		{
			SDL_Rect dRect = {rect.x - camera.getRect().x, rect.y - camera.getRect().y, rect.w, rect.h};
			SDL_RenderCopy(renderer, texture, NULL, &dRect);
		}
		else
		{
			SDL_RenderCopy(renderer, texture, NULL, &rect);
		}
	}
	/*Sprite*/
	void Tile::draw(SDL_Renderer * renderer, Camera& camera)
	{
		if(!is_static)
		{
			SDL_Rect dRect = {rect.x - camera.getRect().x, rect.y - camera.getRect().y, rect.w, rect.h};
			SDL_RenderCopy(renderer, texture, &cropRect, &dRect);
		}
		else
		{
			SDL_RenderCopy(renderer, texture, &cropRect, &rect);
		}
	}
}
