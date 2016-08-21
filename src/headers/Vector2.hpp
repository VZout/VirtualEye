/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

namespace Virtual
{
 	template<typename T> struct Vector2
	{
		T x, y;
		Vector2(T xx, T yy)
		{
			x = xx;
			y = yy;
		}
	};
}
