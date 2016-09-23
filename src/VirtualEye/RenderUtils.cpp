/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../../include/VirtualEye/RenderUtils.hpp"

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
	SDL_Texture * Texture::getTexture()
	{
		return texture;
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
	bool Drawable::isDrawing()
	{
		return is_drawing;
	}
	
	void Drawable::setName(std::string name)
	{
		this->name = name;
	}
	void Drawable::setIsStatic(bool is)
	{
		is_static = is;
	}
	void Drawable::setIsDrawing(bool is)
	{
		is_drawing = is;
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
	bool Transformable::isCollide(Transformable &other)
	{
			if(rect.x < other.getPosition().x + other.getParametres().x && rect.x + rect.w > other.getPosition().x && 
			rect.y < other.getPosition().y + other.getParametres().y && rect.y + rect.h > other.getPosition().y)
				return true;
			else 
				return false;
	}
	/*Sprite*/
	void Sprite::draw(SDL_Renderer * renderer, Camera& camera)
	{
		if(is_drawing)
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
	/*Tile*/
	void Tile::setTile(int n)
	{
		tile = n;
	}
	int Tile::getTile()
	{
		return tile;
	}
	/*Map*/
	std::shared_ptr<Tile> Map::getTileAt(Vector2<int> pos)
	{
		return tiles[pos.x][pos.y];
	}
}
