#include "bat.h"
Bat::Bat(float startx,float starty){
	m_position.x=startx;
	m_position.y=starty;
	m_shape.setSize(sf::Vector2f(50,5));
	m_shape.setPosition(m_position);

}
FloatRect Bat::getPosition(){
	return m_shape.getGlobalBounds();

}
RectangleShape Bat::getShape(){
	return m_shape;

}

void Bat::moveleft(){
	m_movingleft=true;
}

void Bat::moveright(){
	m_movingright=true;
}

void Bat::stopleft(){
	m_movingleft=false;
}

void Bat::stopright(){
	m_movingright=false;
}

void Bat::update(Time dt){
	if(m_movingleft)
		if(m_position.x>0)
			m_position.x-=m_speed*dt.asSeconds();
	if(m_movingright)
		if(m_position.x<910)
			m_position.x+=m_speed*dt.asSeconds();
	m_shape.setPosition(m_position);
	

}
