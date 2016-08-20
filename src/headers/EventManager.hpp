/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <iostream>
#include <SDL2/SDL.h>

namespace Virtual
{
	class EventManager
	{
	public:
		EventManager(void);
		~EventManager();

		/*Check is window closed*/
		bool isClosed(void);

		/*Close window*/
		void close(void);

		/*Capturing events*/
		int pollEvents(void);
	private:
		SDL_Event * event;
		const Uint8 * keyState;
	};
}
