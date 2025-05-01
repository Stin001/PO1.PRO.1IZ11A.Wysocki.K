#pragma once

#include <SFML/Graphics.hpp>
#include "wahadlo.h"
#include "spawnObj.h"
#include "ListaMenage.h"
class game
{
public:

	sf::RenderWindow window;
	wahadlo pendulum;

	// spawnObj object[liczba_object];
	ListaMenage ListMen;


	

	game();
	void run();






};

