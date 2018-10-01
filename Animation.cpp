// Project Includes
#include "Animation.h"

Animation::Animation()
	: m_frames()
	, m_sprite(nullptr)
	, m_playBackSpeed(15.0f)
	, m_loop(false)
	, m_playing(false)
	, m_nextFrameChange()
	, m_currentFrame(0)
{

}

void Animation::Update(sf::Time _frameTime)
{

	//only process the animation if it is playing
	if (m_playing)
	{
		m_nextFrameChange -= _frameTime;
		if (m_nextFrameChange.asSeconds() <= 0)
		{
			//its time to change the frame!
			++m_currentFrame;

			//did we reach the end?
			if (m_currentFrame >= m_frames.size())
			{

				//Reached the end!

				// Should we loop?
				if (m_loop)
				{
					//We should loop

					//Wrap back to beginning
					m_currentFrame = 0;
				}
				else
				{
					// We should not loop

					//Set our frame as last
					m_currentFrame = m_frames.size() - 1;

					//stop playback
					m_playing = false;
				}

				
			}

			//Does our sprite exist
			if (m_sprite)
			{
				m_sprite->setTexture(*m_frames[m_currentFrame]);
			}

			//Determine time for next frame change
			float timeToChange = 1.0f / m_playBackSpeed;
			m_nextFrameChange = sf::seconds(timeToChange);
		}
	}
	//Is it the time to change to a new frame?

}

void Animation::Play()
{

	if (m_sprite)
	{
		m_sprite->setTexture(*m_frames[m_currentFrame]);
	}

	//Only start playing and set next frame time if playback speed is not 0
	//This is to avoid a divide by zero error
	if (m_playBackSpeed != 0)
	{
		//Set play to true
		m_playing = true;

		//Determine time for next frame change
		//Convert frames per second to seconds per frame
		float timeToChange = 1.0f / m_playBackSpeed;
		m_nextFrameChange = sf::seconds(timeToChange);
	}
}

void Animation::Pause()
{
	m_playing = false;
}

void Animation::Stop()
{
	//Stop playback and reset
	m_playing = false;
	m_currentFrame = 0;
}

bool Animation::IsPlaying()
{
	return m_playing;
}

void Animation::AddFrame(sf::Texture& _newFrame)
	{
		m_frames.push_back(&_newFrame);
	}

void Animation::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;
}

void Animation::SetPlayBackSpeed(float _framesPerSecond)
{
	m_playBackSpeed = _framesPerSecond;

	//if the playback speed is zero,
	//pause to protect from divide by zero
	if (m_playBackSpeed == 0)
		Pause();
}

void Animation::SetLoop(bool _loop)
{
	m_loop = _loop;
}