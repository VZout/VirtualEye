/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../../include/VirtualEye/Clock.hpp"

using namespace std::chrono;

namespace Virtual
{
	Clock::Clock()
	{
		timePrev = time_point<high_resolution_clock>(high_resolution_clock::now());
	}
	void Clock::start()
	{
		timeCurrent = high_resolution_clock::now();
	}
	void Clock::stop()
	{
		delta = duration<double>(timeCurrent - timePrev);

		timePrev = high_resolution_clock::now();
	}
	double Clock::getDelta()
	{
		return delta.count();
	}
}
