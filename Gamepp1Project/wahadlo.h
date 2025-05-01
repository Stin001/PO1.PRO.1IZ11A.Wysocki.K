#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <SFML/Audio.hpp>

#define PI 3.141592653
class wahadlo
{
protected:
	float y_w;
	float x_w;

	sf::CircleShape pendulum;
	sf::VertexArray line;
public:
	wahadlo(float x = 400.0f, float y = 400.0f  , float large = 200.0f);
	

	int getx() const; 
	int gety() const;
	void setX(int x);
	void setY(int y);

	const float gravity_earth = 9.80665f;
	
	float time_move = 1.0f / 30.0f;


	// date from file
	 
	float radian45 = PI / 4;
	float radian90 = PI / 2;


	float nachylenie_wahadla_radian = radian90;

	float  large_pendulum = 200.0f;

	float czestosc_wahan = sqrt(gravity_earth / large_pendulum);
	float time_start = 0;
	float wychylenie_max = radian90;

	void tilt(); // wychylenie
	void draw_and_refresh(sf::RenderWindow& window);

	sf::FloatRect getBounds() const;

	sf::SoundBuffer buffer;
	sf::Sound dzwiek_uderz;

	void dzwiek();

	void dzwiek_replay();


	void setPendulumPosition(float x , float y );

};

