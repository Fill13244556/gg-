#pragma once
#include "SFML/Graphics.hpp"
#include "set.h"
bool pointInRect(sf::RectangleShape bat, sf::Vector2f point) {
	float BatX = bat.getPosition().x;
	float BatY = bat.getPosition().y;
	return (point.x >= BatX && point.x <= BatX + BAT_WIDTH)
		&& (point.y >= BatY && point.y <= BatY + BAT_HEIGTH);
}
void initText(sf::Text& ScoreText, int Score, sf::Font& font, const int charSize, const sf::Vector2f textstartpos) {
	ScoreText.setString(std::to_string(Score)); 
	ScoreText.setFont(font); 
	ScoreText.setCharacterSize(charSize); 
	ScoreText.setPosition(textstartpos); 
}