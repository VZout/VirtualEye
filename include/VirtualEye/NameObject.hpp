/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include <string>

class NameObject
{
public:
	/*!
	 *  \brief Sets name of object
	 * 
	 * 	@param name - name of object
	 */
	void setName(std::string name)
	{
		this->name = name;
	}
	/*!
	 * 	@return name of object
	 */
	std::string getName(void)
	{
		return name;
	}
private:
	std::string name;
};