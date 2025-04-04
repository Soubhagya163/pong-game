#include <SFML/Graphics.hpp>
using namespace sf;
class Bat{
	private:
		Vector2f m_position;
		RectangleShape m_shape;
		float m_speed=600.0f;
		bool m_movingleft=false;
		bool m_movingright=false;
	public:
		Bat(float startx,float starty);
		FloatRect getPosition();
		RectangleShape getShape();
		void moveleft();
		void moveright();
		void stopleft();
		void stopright();
		void update(Time dt);

};
