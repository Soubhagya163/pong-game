#include <SFML/Graphics.hpp>
#include <sstream>
#include "bat.h"
#include "ball.h"
using namespace sf;
int main(){
	VideoMode vm(960,540);
	RenderWindow window(vm,"pong game");
	int score=0;
	int lives=3;
	Bat b1(960/2,540-20);
	Ball b2(960/2,0);
	
	Clock clock;
	Text hud;
	Font font;
	font.loadFromFile("KOMIKAP_.ttf");
	hud.setFont(font);
	hud.setCharacterSize(30);
	hud.setFillColor(Color::White);
	hud.setPosition(20,20);
	
	 bool gameOver = false;
	
	while(window.isOpen()){
		Event event1;
		while(window.pollEvent(event1)){
			if(event1.type==event1.Closed)
				window.close();
			 if (event1.type == Event::KeyPressed && event1.key.code == Keyboard::Return && gameOver) {
                
                gameOver = false;
                score = 0;
                lives = 3;
                b1=Bat(960/2,540-20);
                b2 = Ball(960 / 2, 0);
            }
		}
		if(Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();
		if(Keyboard::isKeyPressed(Keyboard::Left))
			b1.moveleft();
		else
			b1.stopleft();
		if(Keyboard::isKeyPressed(Keyboard::Right))
			b1.moveright();
		else
			b1.stopright();
		Time dt=clock.restart();
		b1.update(dt);
		b2.update(dt);
		
		std::stringstream ss;
		
		if(b2.getPosition().left<0 || b2.getPosition().left+b2.getPosition().width>window.getSize().x)
			b2.reboundsides();
		if(b2.getPosition().top<0){
			b2.reboundbatortop();
			score++;
		}
		if(b2.getPosition().top>window.getSize().y){
			b2.reboundbottom();
			lives--;
		
			if (lives < 1) {
                gameOver = true; 
                ss << "Game Over\nPress Enter to restart";
                hud.setString(ss.str());
                b1=Bat(-250,0);
				b2=Ball(-250,0);
            }
		}
		
		if(b2.getPosition().intersects(b1.getPosition()))
			b2.reboundbatortop();
		
		if (!gameOver) { 
            ss << "Score-" << score << " Lives-" << lives;
            hud.setString(ss.str());
        }
			
	
			
			
		window.clear(Color::Black);
		window.draw(hud);
		window.draw(b1.getShape());
		window.draw(b2.getShape());
		
		window.display();
		
	}
	return 0;

}
