#include "../../include/VirtualEye/Device.hpp"

using namespace Virtual;

int mv = 100;

int x = 0;

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
		renderer->loadSprite("res/paddle.png", Vector2<int>(400, 500), "paddle");
		renderer->loadSprite("res/ball.png", Vector2<int>(400, 300), "ball");
		renderer->loadLabel("res/font.ttf", "Hello world", Vector2<int>(10, 10), "text", {0, 255, 0}, 100);
		
		for(int i = 0; i < 3; i++)
			renderer->loadSprite("res/tile.png", Vector2<int>(350 + (i * 75), 10), "tile" + std::to_string(i));
	}
	void onUpdate()
	{
		//Moving the ball
		renderer->getSpriteById("ball").move(Vector2<int>(0, mv), clock->getDelta());

		//Moving the paddle
		renderer->getSpriteById("paddle").setPosition(Vector2<int>(eventManager->getMousePosition().x, 500));
		
		if(x < 120)
		{
			x++ * clock->getDelta();
			renderer->getLabelById("text").setText(std::to_string(x));
		}
		
		//Checking collision
		for(int i = 0; i < 2; i++)
			if(renderer->getSpriteById("ball").isCollide(renderer->getSpriteById("tile" + std::to_string(i)))) 
			{
				renderer->getSpriteById("tile" + std::to_string(i)).setIsDrawing(false);
				renderer->getSpriteById("tile" + std::to_string(i)).setPosition(Vector2<int>(-10, -10));
				mv = -mv;
			}
		if(renderer->getSpriteById("ball").isCollide(renderer->getSpriteById("paddle")))
			mv = -mv;
		
		//Escape
		if(eventManager->isKeyPressed(KEY(ESCAPE))) eventManager->close();
	}
};

int main()
{
	Engine engine(800, 600);
	
	return engine.start("res/test.lua");
}
