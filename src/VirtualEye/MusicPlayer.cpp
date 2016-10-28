/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../../include/VirtualEye/MusicPlayer.hpp"

namespace Virtual
{
	MusicPlayer::MusicPlayer()
	{

	}
	void MusicPlayer::loadMusic(std::string path, std::string name)
	{
		std::shared_ptr<Music> music(new Music);
		
		music->setName(name);
		music->loadMusic(Mix_LoadMUS(path.c_str()));
		
		msc.push_back(music);
	}
	void MusicPlayer::playMusic(std::string name)
	{
		for(auto &i : msc)
		{
			if(i->getName() == name)	i->play();
		}
	}
}
