#include "GameRender.h"

namespace Docking::Client {
	GameRender::GameRender(GameModel& game, sf::RenderWindow& window) :
		m_GameModel(game), 
		m_Window(window),
		m_Square(sf::Vector2f(75, 75))
	{
		m_Square.setOutlineThickness(5);
		m_Square.setOutlineColor(sf::Color::Black);
		w = 80;
		//font.loadFromFile("sansation.ttf");
		//up_text1 = sf::Text("N - New Game,     mouse click - choose block,     Arrow Keys - move", font, 20);
		//up_text1.setPosition(5, 2);
		//up_text2 = sf::Text("Close the enemy or connect all your blocks!", font, 20);
		//up_text2.setPosition(5, 25);

		//red_won = sf::Text("Red player win!", font, 90);
		//red_won.setFillColor(sf::Color::Red);
		//blue_won = sf::Text("Blue player win!", font, 90);
		//blue_won.setFillColor(sf::Color::Blue);
	}

	sf::RenderWindow& GameRender::Window()
	{
		return m_Window;
	}

	void GameRender::draw()
	{
		m_Window.clear(sf::Color(200,210,115));
		//m_Window.draw(up_text1);
		//m_Window.draw(up_text2);
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++)
			{
				m_Square.setPosition(i * w, j * w);

				if (m_GameModel.GetElement({ i, j }) == 1) {
					m_Square.setFillColor(sf::Color(153,255,204));
				}
				else if (m_GameModel.GetElement({ i, j }) == 2) {
					m_Square.setFillColor(sf::Color(0,76,153));
				}

				if (m_GameModel.GetElement({ i, j })) {
					m_Window.draw(m_Square);
				}
			}
		}

		/*if (m_GameModel.GetWinner() == 1) {
			red_won.setPosition(4, 300);
			m_Window.draw(red_won);
		}
		else if (m_GameModel.GetWinner() == 2) {
			blue_won.setPosition(4, 300);
			m_Window.draw(blue_won);
		}*/

		m_Window.display();
	}

	int GameRender::get_element_size()
	{
		return w;
	}
}