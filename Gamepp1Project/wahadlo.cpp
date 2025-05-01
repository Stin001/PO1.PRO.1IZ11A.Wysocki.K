#include "wahadlo.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


wahadlo::wahadlo(float x, float y, float large)
	: x_w(x), y_w(y), large_pendulum(large), line(sf::Lines, 2)
{
	line.setPrimitiveType(sf::Lines);
	line.resize(2);

	pendulum.setRadius(20);
	pendulum.setOrigin(20, 20);
	pendulum.setFillColor(sf::Color::Black);

	float nachylenie = radian45;
	float x_pos = x + large * sin(nachylenie);
	float y_pos = y + large * cos(nachylenie);
	pendulum.setPosition(x_pos, y_pos);

	line[0].position = sf::Vector2f(x, y);
	line[1].position = sf::Vector2f(x_pos, y_pos);
}

void wahadlo::tilt() {

	nachylenie_wahadla_radian = wychylenie_max * cos(czestosc_wahan * time_start);

	float x_pos = x_w + large_pendulum * sin(nachylenie_wahadla_radian);
	float y_pos = y_w + large_pendulum * cos(nachylenie_wahadla_radian);

	pendulum.setPosition(x_pos, y_pos);

	line[0].position = sf::Vector2f(x_w, y_w);
	line[1].position = sf::Vector2f(x_pos, y_pos);


	line[0].color = sf::Color::Red;
	line[1].color = sf::Color::Red;

	time_start = time_start + time_move;
}







void wahadlo::draw_and_refresh(sf::RenderWindow& window)
{
	window.draw(line);
	window.draw(pendulum);
}



sf::FloatRect wahadlo::getBounds() const {
	return pendulum.getGlobalBounds();  
}

void wahadlo::dzwiek() // load saund for  hit  wachadlo block 
{
	
	// buffer / dzwiek 
	

	buffer.loadFromFile("C:\\Users\\isiek\\OneDrive\\Pulpit\\Gamepp1Project\\ShootShip.wav");


	dzwiek_uderz.setBuffer(buffer);
}

void wahadlo::dzwiek_replay()
{

	if(dzwiek_uderz.getStatus() != sf::Sound::Playing)
	dzwiek_uderz.play();
	
}

void wahadlo::setPendulumPosition(float x, float y)
{
	x_w = x ;
	y_w =  y;
	
	line[0] = sf::Vector2f(x_w, y_w);

	tilt();
}











int wahadlo::getx() const
{
	return x_w;
}

int wahadlo::gety() const
{
	return y_w;
}

void wahadlo::setX(int x)
{
	x_w = x;
}

void wahadlo::setY(int y)
{
	y_w = y;
}

