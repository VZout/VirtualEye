/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include <chrono>

namespace Virtual
{
	class Clock
	{
	public:
		Clock();
		
		void start();
		void stop();
		double getDelta();
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> timePrev;
		std::chrono::time_point<std::chrono::high_resolution_clock> timeCurrent;
		std::chrono::duration<double> delta;
	};
}
