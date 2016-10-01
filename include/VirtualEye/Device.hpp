/*  =============================================================*
 *   VirtualEye (c)			Dmitro Szewczuk		 				 *
 *   MIT License  http://choosealicense.com/licenses/mit/		 *
 *  =============================================================*/

#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "EventManager.hpp"
#include "Renderer.hpp"
#include "Clock.hpp"

namespace Virtual
{
	/*Device class manage sublibs and engine*/
	class Device
	{
	public:
		/*Constructor takes width and height of engine window*/
		Device(int, int);
	
		/*Deletes window memory*/
		~Device(void);

		/*Function start main loop*/
		int start();
	protected:
		/*onInit() start before main loop*/
		virtual void onInit(){ };

		/*onUpdate() start in rendering loop*/
		virtual void onUpdate(){ };
		
		/*set width and height of window*/
		void setParametres(Vector2<int>);
		
		/*set is window fullscreened*/
		void setFullScreened(bool);
	protected:
		std::shared_ptr<EventManager> eventManager;
		std::shared_ptr<Renderer> renderer;
		std::shared_ptr<Camera> camera;
		std::shared_ptr<Clock> clock;
		
		Vector2<int> levelProperties;
	private:
		SDL_Window* window;
		int width, height;
		bool fullscreened;
	};
}
