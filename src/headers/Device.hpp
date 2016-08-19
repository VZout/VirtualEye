/*  =============================================================*
 *   VirtualEye (c)			Dmitro Szewczuk						 *
 *	 MIT License  http://choosealicense.com/licenses/mit		 *
 *  =============================================================*/

#include <SDL2/SDL.h>

/*Device class manage sublibs and engine*/
class Device
{
public:
	/*Constructor takes width and height of engine window*/
	Device(int, int);
	
	~Device();
protected:
	/*onInit() start before main loop*/
	virtual	void onInit() = 0;

	/*onUpdate() start in rendering loop*/
	virtual void onUpdate() = 0;
private:
	SDL_Window* window;
};
