///-------------------------
/// Includes
///-------------------------
// Libraries
#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "Animation.h"
#include "AnimationSystem.h"

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

	sf::Sound testSound;
	testSound.setBuffer(AssetManager::GetSoundBuffer("audio/death.wav"));
	testSound.play();

	sf::Text testFont;
	testFont.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	testFont.setString("Finally");

	//Testing Animation
	AnimationSystem testAnimationSystem;
	testAnimationSystem.SetSprite(testSprite);

	Animation& testAnimation = testAnimationSystem.CreateAnimation("run");
	testAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun1.png"));
	testAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun2.png"));
	testAnimation.SetLoop(true);
	testAnimation.SetPlayBackSpeed(10.0f);

	Animation&jumpAnimation = testAnimationSystem.CreateAnimation("jump");
	jumpAnimation.AddFrame(AssetManager::GetTexture("graphics/playerjump.png"));

	testAnimationSystem.Play("run");




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
		sf::Time frameTime = gameClock.restart();

		testAnimationSystem.Update(frameTime);


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
		gameWindow.draw(testFont);

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
