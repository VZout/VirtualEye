/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/

#pragma once

namespace Virtual
{
	/*! 
	 * 	\brief The simple coorinates of Rectangle.
	 *
	 *  Rectangle class manage the parametres of the Rectangle like width, height of they etc.
	 */
	template<typename T> struct Rectangle
	{
		T x, y, w, h;
		
		/*! 
		 * \brief Default zero constructor.
		 *
		 *  This constructor append of each variables zero.
		 */
		Rectangle()
		{
			x = y = w = h = 0;
		}
		/*! 
		 *  \brief Default custom constructor.
		 *
		 * 	@param xx - x value
		 * 	@param yy - y value
		 * 	@param ww - w value
		 * 	@param hh - h value
		 * 
		 *  This constructor append of each variables given values.
		 */
		Rectangle(T xx, T yy, T ww, T hh)
		{
			x = xx;
			y = yy;
			w = ww;
			h = hh;
		}
		/*! 
		 *	\brief Setting position of x and y of upper-left angle.
		 * 
		 * 	@param xx - x value
		 * 	@param yy - y value
		 */
		void setPosition(T xx, T yy)
		{
			x = xx;
			y = yy;
		}
		/*! 
		 * \brief Setting width and height of Rectangle.
		 * 
		 * @param ww - w value
		 * @param hh - h value
		 */
		void setParametres(T ww, T hh)
		{
			w = ww;
			h = hh;
		}
	};
	/*! 
	 * \brief The simple coorinates of one point on the screen.
	 */
 	template<typename T> struct Vector2
	{
		T x, y;
		/*! 
		 *  \brief Default zero constructor.
		 *
		 *  This constructor append of each variables zero.
		 */
		Vector2()
		{
			x = y = 0;
		}
		/*! 
		 *  \brief Default custom constructor.
		 * 
		 * 	@param xx - x value
		 * 	@param yy - y value
		 *
		 *  This constructor append of each variables given values.
		 */
		Vector2(T xx, T yy)
		{
			x = xx;
			y = yy;
		}
	};
	/*! 
	 *  \brief The simple structure of RGB Color.
	 *
	 */
	struct Color
	{
		Uint8 r, g, b;
		/*! 
		 *  \brief Default 255 constructor.
		 *
		 *  This constructor append of each variables 255.
		 */
		Color()
		{
			r = g = b = 255;
		}
		/*! 
		 *  \brief Default custom constructor.
		 * 
		 * 	@param rr - red intensity of color
		 * 	@param gg - gren intensity of color
		 *  @param bb - blue intensity of color
		 *
		 *  This constructor append of each variables given values.
		 */
		Color(float rr, float gg, float bb)
		{
			r = rr;
			g = gg;
			b = bb;
		}
	};
}
