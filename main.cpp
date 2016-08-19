#include "src/headers/Device.hpp"

using namespace Virtual;

class Engine
	: public Device
{
public:
	Engine(int width, int height)
		: Device(width, height)
	{
		
	}
private:
	void onInit()
	{

	}
	void onUpdate()
	{

	}
};

int main()
{
	Engine engine(800, 600);

	return 0;
}
