/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../../include/VirtualEye/MusicPlayer.hpp"

namespace Virtual
{
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
	MusicPlayer::MusicPlayer()
	{
		Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG);
	}
	void MusicPlayer::loadMusic(std::string path, std::string name)
	{
		std::shared_ptr<Music> music(new Music);
		music->name = name;
		music->loadMusic(Mix_LoadMUS(path.c_str()));
		msc.push_back(music);
	}
	void MusicPlayer::playMusic(std::string name)
	{
		for(auto &i : msc)
		{
			if(i->name == name)	i->play();
		}
	}
}
