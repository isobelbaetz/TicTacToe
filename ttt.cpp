#include "ttt.h"

TicTacToe::TicTacToe() {
	
}
void TicTacToe::menuScreen(RenderWindow& window) {
	Font font;
	font.loadFromFile("Summit Attack.ttf");
	Text text;
	text.setFont(font);
	text.setString("~~~~ Welcome to Tic Tac Toe! ~~~~ \n\n\n");
	text.setCharacterSize(40);
	text.setFillColor(sf::Color(200, 0, 60));
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	//player one and player two
	Text players;
	players.setFont(font);
	players.setString("\n\nPlayer 1 will be X's (Huskies) \nPlayer 2 will be O's (Cougs)\n\nThe goal is to get 3 of your shapes in a row, diagonally, vertically, or horizontally.\nThe letters qwe asd zxc will represent the rows and columns of the board\n\n");

	players.setCharacterSize(20);
	players.setFillColor(sf::Color(100, 0, 200));
	window.setFramerateLimit(30);
	//Press enter to continue string
	Text enter;
	enter.setFont(font);
	enter.setString("\n\n\n\n\n\n\n\n\n\n\n\nPress enter to continue...\n");
	enter.setCharacterSize(30);
	enter.setFillColor(sf::Color::Black);
	window.draw(text);
	window.draw(players);
	window.draw(enter);
}
void TicTacToe::drawX(RenderWindow& window, int posX, int posY) {
	ConvexShape x;
	//x.setScale(20.f,20.f);
	x.setPosition(posX, posY);
	x.setPointCount(12);
	x.setFillColor(Color(100, 0, 200));
	x.setPoint(0, sf::Vector2f(0, 5));
	x.setPoint(1, sf::Vector2f(5, 0));
	x.setPoint(2, sf::Vector2f(37, 36));
	x.setPoint(3, sf::Vector2f(75, 0));
	x.setPoint(4, sf::Vector2f(77, 5));
	x.setPoint(5, sf::Vector2f(40,38 ));
	x.setPoint(6, sf::Vector2f(77, 75));
	x.setPoint(7, sf::Vector2f(75, 80));
	x.setPoint(8, sf::Vector2f(37, 42));
	x.setPoint(9, sf::Vector2f(5, 77));
	x.setPoint(10, sf::Vector2f(0, 75));
	x.setPoint(11, sf::Vector2f(35, 38));
	window.draw(x);

	
}
void TicTacToe::drawCircle(RenderWindow& window, int posX,int posY) {
	CircleShape circle(40.f);
	circle.setPointCount(100);
	circle.setFillColor(sf::Color::White);
	circle.setOutlineThickness(10.f);
	circle.setOutlineColor(sf::Color(166, 61, 72));
	circle.setPosition(posX, posY);
	window.draw(circle);
}

void TicTacToe::drawBoard(RenderWindow &window) {
	RectangleShape line(sf::Vector2f(350.f, 5.f));
	line.setPosition(200.f, 50.f);
	line.setFillColor(Color::Black);
	line.rotate(90.f);

	RectangleShape line2(sf::Vector2f(400.f, 5.f));
	line2.setPosition(75.f, 150.f);
	line2.setFillColor(Color::Black);
	line2.rotate(0.f);
	RectangleShape line3(sf::Vector2f(400.f, 5.f));
	line3.setPosition(75.f, 300.f);
	line3.setFillColor(Color::Black);
	line3.rotate(0.f);

	RectangleShape line5(sf::Vector2f(350.f, 5.f));
	line5.setPosition(350.f, 50.f);
	line5.setFillColor(Color::Black);
	line5.rotate(90.f);

	window.draw(line);
	window.draw(line2);
	window.draw(line3);
	window.draw(line3);

	window.draw(line5);

}