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
			
			double getDelta();
		private:
			std::chrono::time_point<std::chrono::high_resolution_clock> timePrev;
	};
}
