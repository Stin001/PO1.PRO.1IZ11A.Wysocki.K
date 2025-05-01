#pragma once
#include "wahadlo.h"

#define liczba_object 200
#define opadanie_speed 2
#define border_down_map 500
class spawnObj : public wahadlo
{
public:
	
	sf::RectangleShape object;
	bool aliveObject = false;


	spawnObj(float x = 0, float y = 0 ) :  wahadlo(x,y,0) {
		object.setSize(sf::Vector2f(30.0f, 30.0f));
		object.setFillColor(sf::Color::Green);
		object.setPosition(x, y);
	}

	void spawnObject(float x, float y) {

		x_w = x;
		y_w = y;

		object.setPosition(x, y);
		aliveObject = true;
	}

	void killObject() {

		aliveObject = false;
	}

	void draw_and_refresh(sf::RenderWindow& window) {

		if (aliveObject == true) { window.draw(object); }
	}

	sf::FloatRect getBounds() const {
		return object.getGlobalBounds();
	}
	

	void opadanie(spawnObj obiekt[], int id_block ) {





		for (int i = 0; i < liczba_object; i++) {


			sf::Vector2f pozycja = object.getPosition();


			if (i == id_block || !obiekt[i].aliveObject) continue; // zabespieczenie przez interkacja obiektu z samym soba 



			      

			float block_under_object = pozycja.y + object.getSize().y;	// zatrzymanie sie na granicy

			if (pozycja.y + object.getSize().y >= border_down_map) {

				object.setPosition(pozycja.x, border_down_map - object.getSize().y);
				return;
			}



			sf::FloatRect next_pozycja = object.getGlobalBounds();            // zatrzymanie sie na innym obiekcie

			next_pozycja.top += opadanie_speed;  // next_pozycja = next_pozycja + opdanie_speed 


			if (next_pozycja.intersects(obiekt[i].getBounds())) {
				
				object.setPosition(pozycja.x, obiekt[i].object.getPosition().y - object.getSize().y);

				return; 
			}


		}

		object.move(0, opadanie_speed);   // pionowe opdania obiektów z predkosci ustalona 
	}

};

