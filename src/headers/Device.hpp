/*  =============================================================*
 *   VirtualEye (c)			Dmitro Szewczuk						 *
 *	 MIT License  http://choosealicense.com/licenses/mit		 *
 *  =============================================================*/

#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "EventManager.hpp"
#include "Renderer.hpp"

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
		virtual	void onInit(void){};

		/*onUpdate() start in rendering loop*/
		virtual void onUpdate(void){};
	protected:
		EventManager * eventManager;
		Renderer * renderer;
	private:
		SDL_Window* window;
	};
}
