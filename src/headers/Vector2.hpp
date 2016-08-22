/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

namespace Virtual
{
 	template<typename T> struct Vector2
	{
		T x, y;
		Vector2()
		{
			x = y = 0;
		}
		Vector2(T xx, T yy)
		{
			x = xx;
			y = yy;
		}
	};
}
