/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include <SDL2/SDL.h>

#include "Math.hpp"

namespace Virtual
{
	/*With Drawable you can manipulate position and parametres objects*/
	class Transformable
	{
	public:
		/*Getters*/
		Vector2<int> getPosition();
		Vector2<int> getParametres();
		Vector2<int> getCropPosition();
		Vector2<int> getCropParametres();
		Rectangle<int> getRectangle();
		
		int getAngle();
		
		Vector2<int> getCenter();

		/*Setters*/
		void setPosition(Vector2<int>);
		void setParametres(Vector2<int>);
		void setCropPosition  (Vector2<int>);
		void setCropParametres(Vector2<int>);
		void setRectangle(Rectangle<int>);
		
		void setAngle(int);

		/*Custom*/
		void move(Vector2<int>, double);
		bool isCollide(Transformable &);
	protected:	
		SDL_Rect rect;
		SDL_Rect cropRect;
		int angle;
	};
}
