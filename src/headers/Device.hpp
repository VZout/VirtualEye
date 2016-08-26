/*  =============================================================*
 *   VirtualEye (c)			Dmitro Szewczuk		 				 *
 *   MIT License  hhttp://choosealicense.com/licenses/mit/		 *
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

		/*Function start main loop*/
		void start();
	protected:
		/*onInit() start before main loop*/
		virtual void onInit(){ };

		/*onUpdate() start in rendering loop*/
		virtual void onUpdate(){ };
	protected:
		EventManager * eventManager;
		Renderer * renderer;
		Camera * camera;
		Vector2<int> levelProperties;
	private:
		SDL_Window* window;
		int width, height;
	};
}
