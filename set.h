#pragma once
#include <string>
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 800.f;
const float WINDOW_HEIGHT = 600.f;
const std::string WINDOW_TITLE = "Game!";

const float BAT_WIDTH = 20.f;
const float BAT_HEIGTH = 100.f;
const float BAT_OFFSET = 30.f;
const sf::Color BAT_COLOR{ sf::Color::Red };
const float FPS = 60.f;
const float BALL_RADIUS = 20.f;
const sf::Color BALL_COLOR{ sf::Color::Yellow };
const float ball_speedx = 10.f; 
const float ball_speedy = 10.f;
const float batSpeed = 5.f; 
//Ñ÷¸ò
const int charSize = 56.f; 
const sf::Vector2f ScoreText(100.f, 50.f);
const sf::Vector2f textstartpos(100.f, 40.f); 

const float batDx = 5.f;
const float batDy = 5.f;