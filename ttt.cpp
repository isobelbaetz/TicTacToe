#include "ttt.h"

//set array 
TicTacToe::TicTacToe() {
	for (int i = 0; i < 9; i++)
		arr[i] = 0;
}

void TicTacToe::setArr(int num, int posI) {
	arr[posI] = num;
}

int TicTacToe::getArr(int i) {
	return arr[i];
}

//gets if they want 1 or 2 players
int TicTacToe::playerchoice(RenderWindow& window) {
	int choice = 0;
	Text text;
	Font font;
	font.loadFromFile("Summit Attack.ttf");
	text.setFont(font);
	text.setString("      Welcome to Tic Tac Toe!\n\nPress 1 to play against a computer\nPress 2 to play with two people :)");
	text.setFillColor(Color::Black);
	text.setCharacterSize(70);
	text.setPosition(300, 90);
	window.draw(text);

	if (Keyboard::isKeyPressed(Keyboard::Num1)) {
		choice = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Num2)) {
		choice = 2;
	}
	return choice;

}

//displays rules
void TicTacToe::menuScreen(RenderWindow& window, int p1s, int p2s, int tie) {
	Font font;
	//load font
	font.loadFromFile("Summit Attack.ttf");
	Text text;
	text.setFont(font);
	text.setString("Welcome to Tic Tac Toe!\n\n");
	text.setCharacterSize(50);
	text.setFillColor(sf::Color(200, 0, 60));
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(830, 20);

	//player one and player two
	Text players;
	players.setFont(font);
	players.setString("\n\nPlayer 1 will be X's (Cougs!) \nPlayer 2 will be O's (Huskies :/)\nThe goal is to get 3 of your shapes in a row,\n diagonally, vertically, or horizontally.\n*The letters qwe asd zxc will represent*\n*the rows and columns of the board*\nX's start first! And then losers.\n");
	players.setPosition(830, 20);
	players.setCharacterSize(35);
	players.setFillColor(sf::Color(137, 137, 137));

	window.setFramerateLimit(30);
	//Display scores
	Text scores;
	scores.setFont(font);
	scores.setString("*Scores*\nCougs: \nHuskies: \nTies: ");
	scores.setCharacterSize(35);
	scores.setFillColor(sf::Color::Black);
	scores.setPosition(830, 520);
	window.draw(text);
	window.draw(players);
	window.draw(scores);

	Text p1score, p2score, ties;
	p1score.setString(std::to_string(p1s));
	p2score.setString(std::to_string(p2s));
	ties.setString(std::to_string(tie));

	p1score.setFont(font);
	p2score.setFont(font);
	ties.setFont(font);

	p1score.setCharacterSize(35);
	p2score.setCharacterSize(35);
	ties.setCharacterSize(35);

	p1score.setFillColor(Color::Black);
	p2score.setFillColor(Color::Black);
	ties.setFillColor(Color::Black);

	p1score.setPosition(950, 575);
	p2score.setPosition(950, 628);
	ties.setPosition(950, 680);
	
	window.draw(p1score);
	window.draw(p2score);
	window.draw(ties);


}

//create an x to display
void TicTacToe::drawX(RenderWindow& window, int posX, int posY) {
	ConvexShape x;

	//x.setScale(20.f,20.f);
	x.setPosition(posX, posY);
	x.setPointCount(12);
	x.setFillColor(sf::Color(166, 61, 72));
	x.setPoint(0, sf::Vector2f(0, 5));
	x.setPoint(1, sf::Vector2f(5, 0));
	x.setPoint(2, sf::Vector2f(37, 36));
	x.setPoint(3, sf::Vector2f(75, 0));
	x.setPoint(4, sf::Vector2f(77, 5));
	x.setPoint(5, sf::Vector2f(40, 38));
	x.setPoint(6, sf::Vector2f(77, 75));
	x.setPoint(7, sf::Vector2f(75, 80));
	x.setPoint(8, sf::Vector2f(37, 42));
	x.setPoint(9, sf::Vector2f(5, 77));
	x.setPoint(10, sf::Vector2f(0, 75));
	x.setPoint(11, sf::Vector2f(35, 38));
	window.draw(x);


}

//create an o to display
void TicTacToe::drawCircle(RenderWindow& window, int posX, int posY) {
	CircleShape circle(40.f);
	circle.setPointCount(100);
	circle.setFillColor(sf::Color::White);
	circle.setOutlineThickness(10.f);
	circle.setOutlineColor(sf::Color(100, 0, 200));
	circle.setPosition(posX, posY);
	window.draw(circle);
}

//draws board and shapes
void TicTacToe::drawBoard(RenderWindow& window, int arr[]) {
	RectangleShape line(sf::Vector2f(700.f, 5.f));
	line.setPosition(300.f, 15.f);
	line.setFillColor(Color::Black);
	line.rotate(90.f);

	RectangleShape line2(sf::Vector2f(700.f, 5.f));
	line2.setPosition(75.f, 475.f);
	line2.setFillColor(Color::Black);
	line2.rotate(0.f);
	RectangleShape line3(sf::Vector2f(700.f, 5.f));
	line3.setPosition(75.f, 225.f);
	line3.setFillColor(Color::Black);
	line3.rotate(0.f);

	RectangleShape line5(sf::Vector2f(700.f, 5.f));
	line5.setPosition(550.f, 15.f);
	line5.setFillColor(Color::Black);
	line5.rotate(90.f);

	window.draw(line);
	window.draw(line2);
	window.draw(line3);
	window.draw(line5);

	//draws shapes
	if (arr[0] == 1) {
		drawX(window, 125, 75);
	}
	if (arr[0] == 2) {
		drawCircle(window, 125, 75);
	}
	if (arr[1] == 1) {
		drawX(window, 375, 75);
	}
	if (arr[1] == 2) {
		drawCircle(window, 375, 75);
	}
	if (arr[2] == 1) {
		drawX(window, 625, 75);
	}
	if (arr[2] == 2) {
		drawCircle(window, 625, 75);
	}
	if (arr[3] == 1) {
		drawX(window, 125, 325);
	}
	if (arr[3] == 2) {
		drawCircle(window, 125, 325);
	}
	if (arr[4] == 1) {
		drawX(window, 375, 325);
	}
	if (arr[4] == 2) {
		drawCircle(window, 375, 325);
	}
	if (arr[5] == 1) {
		drawX(window, 625, 325);
	}
	if (arr[5] == 2) {
		drawCircle(window, 625, 325);
	}
	if (arr[6] == 1) {
		drawX(window, 125, 540);
	}
	if (arr[6] == 2) {
		drawCircle(window, 125, 540);
	}
	if (arr[7] == 1) {
		drawX(window, 375, 540);
	}
	if (arr[7] == 2) {
		drawCircle(window, 375, 540);
	}
	if (arr[8] == 1) {
		drawX(window, 625, 540);
	}
	if (arr[8] == 2) {
		drawCircle(window, 625, 540);
	}
}

//until someone wins, alternates players
int TicTacToe::gamePlay(RenderWindow& window, Player* player1, Player* player2, int curPlayer, int arr[]) {
	int win = 0; 
	if (curPlayer == 1) {
		player1->doMove(arr);
	}
	else if (curPlayer == 2) {
		player2->doMove(arr);
	}

	return checkWin(arr);
}

//gets player 1s move
//int TicTacToe::p1gamePlay(RenderWindow& window, int arr[]) {
//	int placed = 0;
//	while (placed == 0) {
//		if (Keyboard::isKeyPressed(Keyboard::Q) && arr[0] == 0) {
//			arr[0] = 1;
//			placed = 1;
//		}
//		else if (Keyboard::isKeyPressed(Keyboard::W) && arr[1] == 0) {
//			arr[1] = 1;
//			placed = 1;
//
//		}
//		else if (Keyboard::isKeyPressed(Keyboard::E) && arr[2] == 0) {
//			arr[2] = 1;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::A) && arr[3] == 0) {
//			arr[3] = 1;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::S) && arr[4] == 0) {
//			arr[4] = 1;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::D) && arr[5] == 0) {
//			arr[5] = 1;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Z) && arr[6] == 0) {
//			arr[6] = 1;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::X) && arr[7] == 0) {
//			arr[7] = 1;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::C) && arr[8] == 0) {
//			arr[8] = 1;
//			placed = 1;
//
//		}
//	}
//	return checkWin(arr);
//}

//gets player 2s move
//int TicTacToe::p2gamePlay(RenderWindow& window, int arr[]) {
//	int placed = 0;
//	while (placed == 0) {
//		if (Keyboard::isKeyPressed(Keyboard::Q) && arr[0] == 0) {
//			arr[0] = 2;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::W) && arr[1] == 0) {
//			arr[1] = 2;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::E) && arr[2] == 0) {
//			arr[2] = 2;
//			placed = 1;
//		}
//		if (Keyboard::isKeyPressed(Keyboard::A) && arr[3] == 0) {
//			arr[3] = 2;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::S) && arr[4] == 0) {
//			arr[4] = 2;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::D) && arr[5] == 0) {
//			arr[5] = 2;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::Z) && arr[6] == 0) {
//			arr[6] = 2;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::X) && arr[7] == 0) {
//			arr[7] = 2;
//			placed = 1;
//
//		}
//		if (Keyboard::isKeyPressed(Keyboard::C) && arr[8] == 0) {
//			arr[8] = 2;
//			placed = 1;
//
//		}
//	}
//	return checkWin(arr);
//}

//checks to see who won
int TicTacToe::checkWin(int arr[]) {
	if ((arr[0] == arr[1] && arr[1] == arr[2]) || (arr[3] == arr[4] && arr[4] == arr[5]) || (arr[6] == arr[7] && arr[7] == arr[8])) {
		if ((arr[0] == 1 && arr[1] == 1 && arr[2] == 1) || (arr[3] == 1 && arr[4] == 1 && arr[5] == 1) || (arr[6] == 1 && arr[7] == 1 && arr[8] == 1)) {
			return 1;
		}
		if ((arr[0] == 2 && arr[1] == 2 && arr[2] == 2) || (arr[3] == 2 && arr[4] == 2 && arr[5] == 2) || (arr[6] == 2 && arr[7] == 2 && arr[8] == 2)) {
			return 2;
		}
	}
	if ((arr[0] == arr[3] && arr[3] == arr[6]) || (arr[1] == arr[4] && arr[4] == arr[7]) || (arr[2] == arr[5] && arr[5] == arr[8])) {
		if ((arr[0] == 1 && arr[3] == 1 && arr[6] == 1)|| (arr[1] == 1 && arr[4] == 1 && arr[7] == 1) || (arr[2] == 1 && arr[5] == 1 && arr[8] == 1)) {
			return 1;
		}
		if ((arr[0] == 2 && arr[3] == 2 && arr[6] == 2) || (arr[1] == 2 && arr[4] == 2 && arr[7] == 2) || (arr[2] == 2 && arr[5] == 2 && arr[8] == 2)) {
			return 2;
		}
	}

	if (arr[0] == arr[4] && arr[4] == arr[8]) {
		if (arr[0] == 1) {
			return 1;
		}
		if (arr[0] == 2) {
			return 2;
		}
	}
	
	if (arr[2] == arr[4] && arr[4] == arr[6]) {
		if (arr[2] == 1) {
			return 1;
		}
		if (arr[2] == 2) {
			return 2;
		}
	}

	//checks for a tie
	int win;
	for (int j = 0; j < 9; j++) {
		if (arr[j] == 0) {
			return 0;
		}
	}
	return 3;
}