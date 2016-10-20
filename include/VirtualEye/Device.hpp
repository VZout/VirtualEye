/*  =============================================================*
 *   VirtualEye (c)			Dmitro Szewczuk		 				 *
 *   MIT License  http://choosealicense.com/licenses/mit/		 *
 *  =============================================================*/

#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <lua5.2/lua.hpp>

#include "EventManager.hpp"
#include "Renderer.hpp"
#include "Clock.hpp"

namespace Virtual
{
	/*!
	 *  \brief Managment of sublibraries, window and all of the classes of engine.
	 */
	class Device
	{
	public:
		/*!
		 * 	\brief Init of window, all sublibs and all of the subclasses
		 * 
		 *  @param width, height - resolution of window
		 */
		Device(int width, int height);
		~Device(void);
		/*!
		 * 	\brief Starting the work of game engine, run of all scripts
		 * 
		 *  @param path - lua script path
		 */
		int start(std::string path);
	protected:
		/*!
		 *  \brief This function starts before the main loop
		 */
		virtual void onInit(){ };
		/*!
		 *  \brief This function starts in the main loop
		 */
		virtual void onUpdate(){ };
		/*!
		 * 	\brief Starting the work of game engine, run of all scripts
		 *  @param resolution -  resolution of window in integer vector
		 */
		void setParametres(Vector2<int> resolution);
		/*!
		 * 	\brief Setting is the window run in fullscreen mode or not
		 * 
		 *  @param isTrue - true to set fullscreen mode, false to unset fullscreen mode
		 */
		void setFullScreened(bool isTrue);
	protected:
		std::shared_ptr<EventManager> eventManager;
		std::shared_ptr<Renderer> renderer;
		std::shared_ptr<Camera> camera;
		std::shared_ptr<Clock> clock;
		
		Vector2<int> levelProperties;
	private:
		SDL_Window* window;
		lua_State * state;
		int width, height;
		bool fullscreened;
	};
}
