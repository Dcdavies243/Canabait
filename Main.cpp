///-------------------------
/// Includes
///-------------------------
// Libraries
#include <SFML/Graphics.hpp>

#include "AssetManager.h"

int main()
{   ///------------------------
	/// Game Setup
	///------------------------

	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Whack A Critter", sf::Style::Titlebar | sf::Style::Close);

	// Timer Functionality
	sf::Clock gameClock;

	//Create AssetManager
	AssetManager assets;

	// Testing asset manager
	sf::Sprite testSprite;
	testSprite.setTexture(AssetManager::GetTexture("graphics/playerJump.png"));

	///-------------------------
	/// Game Loop
	///-------------------------


	while (gameWindow.isOpen())
	{
		///-------------------------
		/// Input
		///-------------------------

		//TODO: Check for input

		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}
		///-----------------------
		/// Update
		///-----------------------
		sf::Time FrameTime = gameClock.restart();


		///-----------------------
		/// End Update
		///-----------------------


		///-----------------------
		/// Draw
		///-----------------------

		//Clear the window to single colour
		gameWindow.clear();
		//Draw Everything
		gameWindow.draw(testSprite);

		//Display the window contents to the screen
		gameWindow.display();

		///-----------------------
		/// End Draw
		///-----------------------
	}
	//////////////////////
	//End game loop
	//////////////////////

	return 0;
}