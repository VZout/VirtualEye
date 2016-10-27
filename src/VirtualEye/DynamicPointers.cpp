/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../../include/VirtualEye/DynamicPointers.hpp"

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
	/*Music*/
	Music::~Music()
	{
		Mix_FreeMusic(music);
	}
	void Music::loadMusic(Mix_Music *  music)
	{
		this->music = music;
	}
	void Music::play()
	{
		Mix_PlayMusic(music, -1);
	}
}
