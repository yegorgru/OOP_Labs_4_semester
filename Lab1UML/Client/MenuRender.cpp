#include "MenuRender.h"

namespace Docking::Client {
	MenuRender::MenuRender(sf::RenderWindow& window) :
		m_Window(window),
		m_Rectangle(sf::Vector2f(200, 70)) {
		font.loadFromFile("sansation.ttf");
		m_TextPlay = sf::Text("Play", font, 20);
		m_TextLeaders = sf::Text("Leaders", font, 20);
		m_TextExit = sf::Text("Exit", font, 20);
		m_TextPlay.setPosition(30, 100);
		m_TextLeaders.setPosition(30, 300);
		m_TextExit.setPosition(30, 500);
		m_Rectangle.setFillColor(sf::Color(169, 126, 109));
	}

	sf::RenderWindow& MenuRender::Window()
	{
		return m_Window;
	}

	void MenuRender::draw()
	{
		m_Window.clear(sf::Color(223, 236, 157));
		
		for (int i = 1; i <= 5; i += 2) {
			m_Rectangle.setPosition(20, i*100-20);
			m_Window.draw(m_Rectangle);
		}

		m_Window.draw(m_TextPlay);
		m_Window.draw(m_TextLeaders);
		m_Window.draw(m_TextExit);

		m_Window.display();
	}
}