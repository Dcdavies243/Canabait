#pragma once

//Library Includes
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Project Includes
#include "AnimationSystem.h"

class Player
{

public:

	Player();

	void Input(sf::Event _gameEvent);
	void Update(sf::Time _frameTime);
	void Draw(sf::RenderTarget& _target);

private:

	//Assets
	sf::Sprite m_sprite;
	sf::Sound m_jumpsound;
	sf::Sound m_deathsound;
	sf::Sound m_landsound;
	AnimationSystem m_animation;

	//State
	sf::Vector2f m_velocity;
};
