#include "ball.h"
Ball::Ball(float startx,float starty){
	m_position.x=startx;
	m_position.y=starty;
	m_shape.setRadius(10);
	m_shape.setPosition(m_position);

}
FloatRect Ball::getPosition(){
	return m_shape.getGlobalBounds();

}
CircleShape Ball::getShape(){
	return m_shape;

}

void Ball::reboundsides(){
	m_directionx=-m_directionx;
}

void Ball::reboundbatortop(){
	m_directiony=-m_directiony;
}

void Ball::reboundbottom(){
	m_position.y=9;
	m_position.x=400;
}


void Ball::update(Time dt){
	
	m_position.y+=m_directiony*m_speed*dt.asSeconds();
	m_position.x+=m_directionx*m_speed*dt.asSeconds();
	m_shape.setPosition(m_position);

}
