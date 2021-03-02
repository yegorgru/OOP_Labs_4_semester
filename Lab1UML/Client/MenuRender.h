#pragma once

#include <SFML/Graphics.hpp>

namespace Docking::Client {
	class MenuRender
	{
	public:
		MenuRender(sf::RenderWindow& window);
		sf::RenderWindow& Window();
		void draw();
	private:
		sf::RenderWindow& m_Window;
		sf::RectangleShape m_Rectangle;

		sf::Text m_TextPlay;
		sf::Text m_TextLeaders;
		sf::Text m_TextExit;

		sf::Font font;
	};
}
