#include "../../include/VirtualEye/Device.hpp"

using namespace Virtual;

int mv = 100;

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
		renderer->loadSprite("paddle.png", Vector2<int>(400, 500), "paddle");
		renderer->loadSprite("ball.png", Vector2<int>(400, 300), "ball");
		
		for(int i = 0; i < 3; i++)
			renderer->loadSprite("tile.png", Vector2<int>(350 + (i * 75), 10), "tile" + std::to_string(i));
	}
	void onUpdate()
	{
		//Moving the ball
		renderer->getElementById("ball").move(Vector2<int>(0, mv), clock->getDelta());

		//Moving the paddle
		renderer->getElementById("paddle").setPosition(Vector2<int>(eventManager->getMousePosition().x, 500));
		
		//Checking collision
		for(int i = 0; i < 2; i++)
			if(renderer->getElementById("ball").isCollide(renderer->getElementById("tile" + std::to_string(i)))) 
			{
				renderer->getElementById("tile" + std::to_string(i)).setIsDrawing(false);
				renderer->getElementById("tile" + std::to_string(i)).setPosition(Vector2<int>(-10, -10));
				mv = -mv;
			}
		if(renderer->getElementById("ball").isCollide(renderer->getElementById("paddle")))
			mv = -mv;
		
		//Escape
		if(eventManager->isKeyPressed(KEY(ESCAPE))) eventManager->close();
	}
};

int main()
{
	Engine engine(800, 600);
	
	return engine.start();
}
