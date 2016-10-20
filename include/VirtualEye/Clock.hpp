/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include <chrono>

namespace Virtual
{
	/*!
	 *  \brief Managment of time.
	 */
	class Clock
	{
	public:
		Clock(void);
		/*!
		 *  \brief Start of the time catching.
		 */
		void start(void);
		/*!
		 *  \brief Catching, calculating the time.
		 */
		void stop(void);
		/*!
		 *  @return In-double odd of the start and stop time
		 */
		double getDelta(void);
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> timePrev;
		std::chrono::time_point<std::chrono::high_resolution_clock> timeCurrent;
		std::chrono::duration<double> delta;
	};
}
