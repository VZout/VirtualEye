/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <memory>
#include <vector>
#include <string>

namespace Virtual
{
	class Music
	{
	public:
		~Music();
		
		void loadMusic(Mix_Music * music);
		void play();
		
		std::string name;
	private:
		Mix_Music * music;
	};
	/*!
	 *  \brief Class to play music
	 */
	class MusicPlayer
	{
	public:
		MusicPlayer();
		
		void loadMusic(std::string path, std::string name);
		void playMusic(std::string name);
	private:
		std::vector<std::shared_ptr<Music>> msc;
	};
}
