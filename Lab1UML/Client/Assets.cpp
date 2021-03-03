#include "Assets.h"

namespace Docking::Client{
	Assets::Assets() {
		if (!m_Font.loadFromFile("sansation.ttf")) throw;
	}

	sf::Font& Assets::GetFont()
	{
		return m_Font;
	}
}
