/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Vector2.hpp"

namespace Virtual
{
	#define KEY(x) SDLK_##x
	#define MOUSE_KEY(x) SDL_BUTTON_##x
	
	class EventManager
	{
	public:
		EventManager(void);
		~EventManager();

		/*Check is window closed*/
		bool isClosed(void);
		
		/*Check is key pressed*/
		bool isKeyPressed(int);
		
		bool isMouseKeyPressed(int);

		/*Close window*/
		void close(void);

		/*Capturing events*/
		int pollEvents(void);
		
		Vector2<int> getMousePosition();
	private:
		SDL_Event * event;
		const Uint8 * keyState;
	};
}
