/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../../include/VirtualEye/DebugLog.hpp"

namespace Virtual
{
	DebugLog::DebugLog()
	{
		
	}
	DebugLog::DebugLog(const DebugLog &)
	{
		
	}
	DebugLog & DebugLog::getInstance()
	{
		static DebugLog instance;
		return instance;
	}
	void DebugLog::addToLog(std::string string)
	{
		log.push_back(string);
	}
	void DebugLog::printLog()
	{
		std::ofstream file("VirtualEye log.txt");
		
		for(int i = 0; i < log.size(); i++)
			file << log[i] << std::endl;
			
		file.close();
	}
}
