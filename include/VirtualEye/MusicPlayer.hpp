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

#include "DynamicPointers.hpp"

namespace Virtual
{
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
