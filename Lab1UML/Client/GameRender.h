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

	private:
		GameModel& m_GameModel;

		sf::RenderWindow& m_Window;

		sf::RectangleShape m_Square;

		//sf::Font font;

		//sf::Text up_text1;
		//sf::Text up_text2;
		//sf::Text red_won;
		//sf::Text blue_won;
		int w;
	};
}
