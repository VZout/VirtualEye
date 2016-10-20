/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include <string>
#include <vector>
#include <fstream>

namespace Virtual
{
	/*!
	 *  \brief Singleton to manage debugging
	 */
	class DebugLog
	{
	private:
		DebugLog();
		DebugLog(const DebugLog &);
	private:
		std::vector<std::string> log;
	public:
		/*!
		 *  @return instance to singleton
		 */
		static DebugLog & getInstance();
		/*!
		 * \brief Adds the string into log
		 * 
		 * @param string - Value that want to print into debug log
		 */
		void addToLog(std::string string);
		/*!
		 *  \brief create debug log file and print to they all logs
		 */
		void printLog();
	};
}
