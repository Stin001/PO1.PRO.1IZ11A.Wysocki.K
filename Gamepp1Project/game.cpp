#include "game.h"
#include "spawnObj.h"
#include <iostream>
#include <SFML/Graphics.hpp>
game::game()

	: window(sf::VideoMode(800, 600), "ball destroy "),
	pendulum(400.0f, 100.0f, 300.0f)
{

	pendulum.dzwiek();

	window.setFramerateLimit(60); 
}



void game::run()
{
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) { window.close(); }


			

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)   // spawn obiektów 
			{

				ListMen.add(event.mouseButton.x, event.mouseButton.y);
				 /* for (int i = 0; i < liczba_object; i++) {

					if (!object[i].aliveObject) {
						object[i].spawnObject(event.mouseButton.x, event.mouseButton.y);
						break;
					}
					
				} */
			}
		}

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) { //  zmiana miejsca punktu zawieszani wahad³a 
			
			

			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

			

			pendulum.setPendulumPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
			

			
			
		}

		/*
		

		for (int i = 0; i < liczba_object; i++) {     // dzialanie grawitacji 

			object[i].opadanie(object, i);
		}

		pendulum.tilt();

		for (int i = 0; i < liczba_object; i++) {            // znikanie obiektów 

			if (object[i].aliveObject && object[i].getBounds().intersects(pendulum.getBounds())) {

				object[i].killObject();

				pendulum.dzwiek_replay();
			}

			
		}
		
		
		

		window.clear(sf::Color::White);                 // obsluga wyswietlania obrazu 
		pendulum.draw_and_refresh(window);

		for (int i = 0; i < liczba_object; i++) {

			object[i].draw_and_refresh(window);
		}

		*/


		ListMen.updatePhysics();          
		pendulum.tilt();                      
		ListMen.checkCollision(pendulum);  
		ListMen.removeDead();              

		window.clear(sf::Color::White);
		pendulum.draw_and_refresh(window);
		ListMen.drawAll(window);
		

		ListMen.printList();


		window.display();

	}



}

