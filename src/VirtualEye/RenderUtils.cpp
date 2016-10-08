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
	/*Sprite*/
	void Sprite::draw(SDL_Renderer * renderer, Camera& camera)
	{
		if(is_drawing)
		{
			if(!is_static)
			{
				SDL_Rect dRect = {rect.x - camera.getRect().x, rect.y - camera.getRect().y, rect.w, rect.h};
				SDL_RenderCopyEx(renderer, texture, &cropRect, &dRect, angle, NULL, flip);
			}
			else
			{
				SDL_RenderCopyEx(renderer, texture, &cropRect, &rect, angle, NULL, flip);
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
	/*Font*/
	Font::~Font()
	{
		TTF_CloseFont(font);
	}
	void Font::setFont(TTF_Font* font)
	{
		this->font = font;
	}
	TTF_Font* Font::getFont()
	{
		return font;
	}
}
