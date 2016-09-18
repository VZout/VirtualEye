#include "../../include/VirtualEye/Device.hpp"
#include <string>

using namespace Virtual;

Vector2<int> velocity;

class Engine
	: public Device
{
public:
	Engine(int width, int height)
		: Device(width, height)
	{ }
private:
	void onInit()
	{
		levelProperties = renderer->loadMap("ini.iom");
		renderer->loadSprite("player.png", {25, 25}, "player");
	}
	void onUpdate()
	{
		velocity = Vector2<int>(0, 0);
		
		if(eventManager->isKeyPressed(KEY(RIGHT))) velocity.x += 4;
		if(eventManager->isKeyPressed(KEY(LEFT)))  velocity.x -= 4;
		
		camera->setCenter(renderer->getElementById("player").getPosition());
		renderer->getElementById("player").move(velocity);
	}
};

int main()
{
	Engine engine(800, 600);
	
	return engine.start();
}
