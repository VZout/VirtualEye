/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

namespace Virtual
{
	template<typename T> struct Rectangle
	{
		T x, y, w, h;
		Rectangle()
		{
			x = y = w = h = 0;
		}
		Rectangle(T xx, T yy, T ww, T hh)
		{
			x = xx;
			y = yy;
			w = ww;
			h = hh;
		}
		void setPosition(T xx, T yy)
		{
			x = xx;
			y = yy;
		}
		void setParametres(T ww, T hh)
		{
			w = ww;
			h = hh;
		}
	};
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
