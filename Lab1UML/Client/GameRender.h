#pragma once

#include <SFML/Graphics.hpp>

#include "GameModel.h"

namespace Docking::Client {
	class GameRender
	{
	public:
		GameRender(GameModel& game, sf::RenderWindow& window);
		sf::RenderWindow& Window();
		void draw();

		int get_element_size();

		void SetEndText(const std::string& text);

		void Restore();
	private:
		GameModel& m_GameModel;

		sf::RenderWindow& m_Window;

		sf::RectangleShape m_Square;

		sf::Font m_Font;

		sf::Text m_TextPlayers;

		sf::Text m_TextEnd;
		sf::Text m_TextWaiting;
		int w;
	};
}
