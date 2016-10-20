/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "Math.hpp"

namespace Virtual
{
	#define KEY(x) SDLK_##x
	#define MOUSE_BUTTON(x) SDL_BUTTON_##x
	
	/*! 
	 *	\brief Management of event queque.
	 */
	class EventManager
	{
	public:
		EventManager(void);
		~EventManager();
		/*!
		 *  \brief Check is the window closed.
		 * 
		 *  @return true if window x button is clicked or false when it isn't
		 */
		bool isClosed(void);
		/*!
		 *  \brief Check is the keyboard key pressed.
		 * 
		 *  @return true if keyboard key pressed is clicked or false when it isn't
		 * 
		 *	@param id - KEY(x) where x is the name of key like LEFT
		 */
		bool isKeyPressed(int id);
		/*!
		 *  \brief Check is the mouse key pressed.
		 * 
		 *  @return true if mouse key pressed is clicked or false when it isn't
		 * 
		 *  @param id - MOUSE_BUTTON(x) where x is the name of key like LEFT
		 */
		bool isMouseKeyPressed(int id);
		/*!
		 *  \brief Colse the window
		 */
		void close(void);
		/*!
		 *  \brief Polling all events into queque
		 * 
		 * 	@return Number of current event
		 */
		int pollEvents(void);
		/*!
		 *  \brief Catch the mouse position
		 * 
		 * 	@return Mouse position relative to window
		 */
		Vector2<int> getMousePosition(void);
	private:
		SDL_Event * event;
		const Uint8 * keyState;
	};
}
