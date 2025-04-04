#include <SFML/Graphics.hpp>
using namespace sf;
class Ball{
	private:
		Vector2f m_position;
		CircleShape m_shape;
		float m_speed=1000.0f;
		float m_directionx=0.2f;
		float m_directiony=0.2f;
	public:
		Ball(float startx,float starty);
		FloatRect getPosition();
		CircleShape getShape();
		void reboundsides();
		void reboundbatortop();
		void reboundbottom();
		
		void update(Time dt);

};
