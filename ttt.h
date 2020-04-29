#pragma once
#ifndef TTT_H
#define TTT_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
class TicTacToe {
private:


public:
	//constructor not made yet
	TicTacToe();
	//drawing the board and takes in the render window
	void drawBoard(RenderWindow &window);
	//drawing the circle posx and posy determines where on the board it will lie
	void drawCircle(RenderWindow& window, int posX, int posY);
	//drawing the x posx and posy determine where on the board it will lie
	void drawX(RenderWindow& window, int posX, int posY);
	void menuScreen(RenderWindow& window);
};



#endif