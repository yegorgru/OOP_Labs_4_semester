#include "GameRender.h"

#include <string>

namespace Docking::Client {
	GameRender::GameRender(GameModel& game, sf::RenderWindow& window) :
		m_GameModel(game), 
		m_Window(window),
		m_Square(sf::Vector2f(75, 75))
	{
		Restore();
	}

	sf::RenderWindow& GameRender::Window()
	{
		return m_Window;
	}

	void GameRender::draw()
	{
		m_Window.clear(sf::Color(223,236,157));
		if (m_GameModel.GetPlayers().size() < 2) {
			m_Window.draw(m_TextWaiting);
		}
		else if (m_TextEnd.getString().getSize() > 0) {
			m_Window.draw(m_TextEnd);
		}
		else {
			const auto& players = m_GameModel.GetPlayers();
			std::string playersStr = players[0].GetName();
			while (playersStr.size() < 10) {
				playersStr += '.';
			}
			playersStr += ".........." + std::to_string(players[0].GetWins());
			playersStr += "                                         ";
			playersStr += std::to_string(players[1].GetWins()) + "..........";
			for (size_t i = 0; i < 10 - players[1].GetName().size(); i++) {
				playersStr += '.';
			}
			playersStr += players[1].GetName();
			m_TextPlayers.setString(playersStr);
			m_Window.draw(m_TextPlayers);
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++)
				{
					m_Square.setPosition(i * w, 50 + j * w);

					if (m_GameModel.GetElement({ i, j }) == 1) {
						m_Square.setFillColor(sf::Color(153, 255, 204));
					}
					else if (m_GameModel.GetElement({ i, j }) == 2) {
						m_Square.setFillColor(sf::Color(0, 76, 153));
					}

					if (m_GameModel.GetElement({ i, j })) {
						m_Window.draw(m_Square);
					}
				}
			}
		}

		m_Window.display();
	}

	int GameRender::get_element_size() {
		return w;
	}

	void GameRender::SetEndText(const std::string& text) {
		m_TextEnd.setString(text);
	}

	void GameRender::Restore() {
		m_Square.setOutlineThickness(5);
		m_Square.setOutlineColor(sf::Color::Black);
		w = 80;
		m_Font.loadFromFile("sansation.ttf");
		m_TextWaiting = sf::Text("Waiting for opponent", m_Font, 50);
		m_TextWaiting.setPosition(50, 300);
		m_TextPlayers = sf::Text("", m_Font, 30);
		m_TextPlayers.setPosition(30, 10);
		m_TextPlayers.setFillColor(sf::Color::Black);
		m_TextEnd = sf::Text("", m_Font, 50);
		m_TextEnd.setPosition(100, 300);
		m_TextEnd.setFillColor(sf::Color::Red);
	}
}