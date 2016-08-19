/*  =============================================================*
 *   VirtualEye (c)			Dmitro Szewczuk						 *
 *	 MIT License  http://choosealicense.com/licenses/mit		 *
 *  =============================================================*/

#pragma once

#include <SDL2/SDL.h>

#include "EventManager.hpp"

namespace Virtual
{
	/*Device class manage sublibs and engine*/
	class Device
	{
	public:
		/*Constructor takes width and height of engine window*/
		Device(int, int);
	
		~Device(void);
	protected:
		/*onInit() start before main loop*/
		virtual	void onInit(void) = 0;

		/*onUpdate() start in rendering loop*/
		virtual void onUpdate(void) = 0;
	protected:
		EventManager * eventManager;
	private:
		SDL_Window* window;
	};
}
