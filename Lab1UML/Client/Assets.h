#pragma once

#include <SFML/Graphics.hpp>
#include "Singleton.h"

namespace Docking::Client {
	class Assets : public Singleton<Assets>
	{
	public:
		sf::Font& GetFont();

	private:
		Assets();
		
		sf::Font m_Font;

		friend class Singleton<Assets>;
	};
}

