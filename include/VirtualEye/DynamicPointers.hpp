/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#pragma once

#include "NameObject.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

namespace Virtual
{
	/*!
	 *  \brief Dynamic texture class, like Font
	*/
	class Texture
	{
	public:
		~Texture();
		/*!
		 *  \brief Dynamic texture class
		 * 
		 * 	@param texture - pointer into SDL_Texture viariable
		 */
		void setTexture(SDL_Texture* texture);
		/*!
		 * 	@return SDL_Texture pointer
		 */
		SDL_Texture* getTexture();
	protected:
		SDL_Texture * texture;	
	};
	/*!
	 * \brief Dynamic Music class
	 */
	class Music
			: public NameObject
	{
	public:
		~Music();
		/*!
		 * \brief Loading SDL music pointer into dynamic class
		 * 
		 * @param music - SDL default pointer
		 */
		void loadMusic(Mix_Music * music);
		/*!
		 * \brief Plays the music
		 */
		void play();
	private:
		Mix_Music * music;
	};
	/*!
	 *  \brief Simple font dynamic class, like Texture
	 */
	class Font
	{
	public:
		~Font();
		/*!
		 *  \brief Setting traditional SDL pointer
		 * 
		 * 	@param font - pointer into TTF_Font viariable
		 */
		void setFont(TTF_Font* font);
		/*!
		 * 	@return TTF_Font pointer
		 */
		TTF_Font* getFont();
	private:
		TTF_Font* font;	
	};
}
