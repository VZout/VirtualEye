/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace Virtual
{
	class DebugLog
	{
	private:
		DebugLog();
		DebugLog(const DebugLog &);
	private:
		std::vector<std::string> log;
	public:
		static DebugLog & getInstance();
		void addToLog(std::string);
		void printLog();
	};
}
