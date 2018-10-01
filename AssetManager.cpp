//Library Includes
#include <assert.h>

//Project Includes
#include "AssetManager.h"

//Initialise the static reference to our instance - to nullptr (aka zero)
AssetManager* AssetManager::s_instance = nullptr;

//Cunstructor
AssetManager::AssetManager()

	:m_textures()
	,m_soundBuffers()
	,m_fonts()
{
	//Trow an error and stop execution (in debug mode) if a copy has been created

	assert(s_instance == nullptr);

	//ASsign ourselves to the instance pointer
	//This is the new instance of the class that has just been created
	s_instance = this;
}

sf::Texture& AssetManager::GetTexture(std::string _fileName)
{
	//Create an iterator to hold a key and value pair
	//and search for the required key
	//using the passed in file name

	auto keyValuePair = s_instance->m_textures.find(_fileName);
	// "auto" in this case is equivalent to writting std::map<std::string,sf::Teexture>::iterator;
	// This keyword (auto) can be used in cases where the compiler can figue out the type of the variable for you
	// YOU ARE NOT ALLOWED TO USE THIS EXCEPT FOR ITERATORS

	//Dide we find the texture? (aka was it already loaded?)
	//(iterator will be at hte end if we did NOT find it

	if (keyValuePair != s_instance->m_textures.end())
	{
		//YES! We Found it!
		return keyValuePair->second;
	}
	else
	{
		//NO! We didn't find it

		//Lets create it then!

		//Create a new key value pair using hte filename
		//The subscript [] operator creates an entry in
		// the map if thesre is not already one there

		sf::Texture& texture = s_instance->m_textures[_fileName];

		//blank texture has been created
		//now just load it from file using sfml

		texture.loadFromFile(_fileName);

		//return the texture to the calling code
		return texture;
	}
}

sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string _fileName)
{
	//Create an iterator to hold a key and value pair
	//and search for the required key
	//using the passed in file name

	auto keyValuePair = s_instance->m_soundBuffers.find(_fileName);
	// "auto" in this case is equivalent to writting std::map<std::string,sf::Teexture>::iterator;
	// This keyword (auto) can be used in cases where the compiler can figue out the type of the variable for you
	// YOU ARE NOT ALLOWED TO USE THIS EXCEPT FOR ITERATORS

	//Dide we find the texture? (aka was it already loaded?)
	//(iterator will be at hte end if we did NOT find it

	if (keyValuePair != s_instance->m_soundBuffers.end())
	{
		//YES! We Found it!
		return keyValuePair->second;
	}
	else
	{
		//NO! We didn't find it

		//Lets create it then!

		//Create a new key value pair using hte filename
		//The subscript [] operator creates an entry in
		// the map if thesre is not already one there

		sf::SoundBuffer& soundBuffer = s_instance->m_soundBuffers[_fileName];

		//blank texture has been created
		//now just load it from file using sfml

		soundBuffer.loadFromFile(_fileName);

		//return the texture to the calling code
		return soundBuffer;
	}
}

sf::Font& AssetManager::GetFont(std::string _fileName)
{
	//Create an iterator to hold a key and value pair
	//and search for the required key
	//using the passed in file name

	auto keyValuePair = s_instance->m_fonts.find(_fileName);
	// "auto" in this case is equivalent to writting std::map<std::string,sf::Teexture>::iterator;
	// This keyword (auto) can be used in cases where the compiler can figue out the type of the variable for you
	// YOU ARE NOT ALLOWED TO USE THIS EXCEPT FOR ITERATORS

	//Dide we find the texture? (aka was it already loaded?)
	//(iterator will be at hte end if we did NOT find it

	if (keyValuePair != s_instance->m_fonts.end())
	{
		//YES! We Found it!
		return keyValuePair->second;
	}
	else
	{
		//NO! We didn't find it

		//Lets create it then!

		//Create a new key value pair using hte filename
		//The subscript [] operator creates an entry in
		// the map if thesre is not already one there

		sf::Font& font = s_instance->m_fonts[_fileName];

		//blank texture has been created
		//now just load it from file using sfml

		font.loadFromFile(_fileName);

		//return the texture to the calling code
		return font;
	}
}