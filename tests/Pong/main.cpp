#include "../../include/VirtualEye/Device.hpp"

using namespace Virtual;

int x = 0;
Vector2<int> mv(75, 200);
int max = 10;

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
		musicPlayer->loadMusic("res/sound.mp3", "pong");
		
		for(int i = 0; i < max; i++)
		{
			renderer->loadSprite("res/tile.png", Vector2<int>(10 + (i * 75), 50), "tile" + std::to_string(i));
			renderer->getSpriteById("tile"+std::to_string(i)).setParametres(Vector2<int>(50, 50));
		}
		
		renderer->loadLabel("res/font.ttf", "Your points: ", Vector2<int>(10, 10), "text", {0, 0, 0}, 35);
	}
	void onUpdate()
	{
		//Label changing
		renderer->getLabelById("text").setText(std::to_string(x));
		
		//Moving ball
		renderer->getSpriteById("ball").move(mv, clock->getDelta());
		
		//Collision
		if(renderer->getSpriteById("paddle").isCollide(renderer->getSpriteById("ball")))
			mv.y = -mv.y;
		for(int i = 0; i < max; i++)
		{
			if(renderer->getSpriteById("tile"+std::to_string(i)).isCollide(renderer->getSpriteById("ball")))
			{
				//musicPlayer->playMusic("pong");
				renderer->getSpriteById("tile"+std::to_string(i)).setPosition(Vector2<int>(-100, -100));
				renderer->getSpriteById("tile"+std::to_string(i)).setIsDrawing(false);
				mv.y = -mv.y;
				mv.x = -mv.x;
				x+=100;
			}
		}
		if(renderer->getSpriteById("ball").getPosition().x < 0)
			mv.x = -mv.x;
		if(renderer->getSpriteById("ball").getPosition().y < 0)
			mv.y = -mv.y;
		if(renderer->getSpriteById("ball").getPosition().x > 800)
			mv.y = -mv.y;
		if(renderer->getSpriteById("ball").getPosition().y > 600)
		{
			renderer->getSpriteById("ball").setPosition(Vector2<int>(-1000, -1000));
			renderer->getSpriteById("ball").setIsDrawing(false);
		}
		
		//Paddle moving
		renderer->getSpriteById("paddle").setPosition(Vector2<int>(eventManager->getMousePosition().x, 500));
		
		//Escape
		if(eventManager->isKeyPressed(KEY(ESCAPE))) eventManager->close();
	}
};

int main()
{
	Engine engine(800, 600);
	
	return engine.start("res/test.lua");
}
