#include <SFML/Graphics.hpp>
#include <iostream>
#include "ttt.h"
using namespace sf;
int main() {
	RenderWindow window(sf::VideoMode(1000, 800), "Tic Tac Toe");
	
	Event event;
	
	
	//playing the music and opening the file for tic tac toe
	Music music;
	if (!music.openFromFile("Washington_State__WSU_Fight_Song.ogg")) {
		std::cout << "error";
	}
	music.play();
	
	
	TicTacToe player;
	

	while (window.isOpen()) {
		
			window.clear(sf::Color::White);
			player.menuScreen(window);
			//testing the drawing functions
			//player.drawBoard(window);
			//player.drawCircle(window,100.f,50.f);
			//player.drawX(window, 100.f, 50.f);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					//still cant get this to work 
					window.clear(Color::White);
					player.drawBoard(window);
				}

			
		//allows the program to close the text.
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.display();
	}


	return 0;

}
