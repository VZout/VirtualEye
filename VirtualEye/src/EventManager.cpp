/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

 #include "../include/EventManager.hpp"

 namespace Virtual
 {
 	EventManager::EventManager(void)
	{
		event = new SDL_Event();
	}
	EventManager::~EventManager(void)
	{
		delete event;
	}
	int EventManager::pollEvents(void)
	{
		keyState = SDL_GetKeyboardState(NULL);
		
		return SDL_PollEvent(event);
	}
	bool EventManager::isClosed(void)
	{
		if(event->type == SDL_QUIT)
			return true;
		else 
			return false;
	}
	bool EventManager::isKeyPressed(int key)
	{
		if(keyState[SDL_GetScancodeFromKey(key)])
			return true;
		else
			return false;
	}
	bool EventManager::isMouseKeyPressed(int key)
	{
		if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
			return true;
		else
			return false;
	}
	void EventManager::close(void)
	{
		event->type = SDL_QUIT;
	}
	Vector2<int> EventManager::getMousePosition()
	{
		Vector2<int> pos(0, 0);
		SDL_GetMouseState(&pos.x, &pos.y);
		return pos;
	}
 }
