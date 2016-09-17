#include "../../include/Device.hpp"

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
		renderer->loadLabel("Slimamif.ttf", "Hello", Vector2<int>(100, 100), Color(0, 0, 0), "text", 100);
	}
	void onUpdate()
	{
		velocity = Vector2<int>(0, 0);
		
		if(eventManager->isKeyPressed(KEY(RIGHT))) velocity.x += 4;
		if(eventManager->isKeyPressed(KEY(LEFT)))  velocity.x -= 4;
		
		if(renderer->getElementById("player").isCollide(*renderer->getMap()->getTileAt(Vector2<int>(0, 0))))
			std::cout << "a" << std::endl;
		
		camera->setCenter(renderer->getElementById("player").getPosition());
		renderer->getElementById("player").move(velocity);
	}
};

int main()
{
	Engine engine(800, 600);
	
	return engine.start();
}
