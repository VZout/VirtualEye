#include <SDL2/SDL.h>

class Device
{
public:
	Device(int, int);
	~Device();

protected:
	void onInit() = 0;
	void onUpdate() = 0;

private:
	SDL_Window* window;
}
