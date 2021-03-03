#include "LogRender.h"
#include "Assets.h"

namespace Docking::Client {
	LogRender::LogRender(sf::RenderWindow& window) :
		m_Window(window),
		m_RectangleName(sf::Vector2f(400, 70)),
		m_RectanglePassword(sf::Vector2f(400, 70)),
		m_RectangleLog(sf::Vector2f(190, 50))
	{
		m_TextName = sf::Text("", Assets::Get().GetFont(), 20);
		m_TextPassword = sf::Text("", Assets::Get().GetFont(), 20);
		m_TextLogIn = sf::Text("Log In", Assets::Get().GetFont(), 20);
		m_TextLogUp = sf::Text("Log Up", Assets::Get().GetFont(), 20);
		m_TextNameTitle = sf::Text("Name", Assets::Get().GetFont(), 20);
		m_TextPasswordTitle = sf::Text("Password", Assets::Get().GetFont(), 20);
		m_TextName.setPosition(30, 100);
		m_TextNameTitle.setPosition(30, 50);
		m_TextPassword.setPosition(30, 300);
		m_TextPasswordTitle.setPosition(30, 250);
		m_TextLogIn.setPosition(30, 490);
		m_TextLogUp.setPosition(240, 490);
		m_RectangleName.setFillColor(sf::Color::White);
		m_RectanglePassword.setFillColor(sf::Color::White);
		m_RectangleLog.setFillColor(sf::Color(169, 126, 109));

		m_RectangleName.setPosition(20, 80);
		m_RectanglePassword.setPosition(20, 280);
		m_RectangleName.setOutlineColor(sf::Color::Black);
		m_RectanglePassword.setOutlineColor(sf::Color::Black);

		m_TextName.setFillColor(sf::Color::Black);
		m_TextPassword.setFillColor(sf::Color::Black);
		m_TextNameTitle.setFillColor(sf::Color::Black);
		m_TextPasswordTitle.setFillColor(sf::Color::Black);
		SetFocus(0);
	}

	sf::RenderWindow& LogRender::Window() {
		return m_Window;
	}

	void LogRender::Draw() {
		m_Window.clear(sf::Color(223, 236, 157));

		m_Window.draw(m_RectangleName);
		m_Window.draw(m_RectanglePassword);

		m_RectangleLog.setPosition(20, 480);
		m_Window.draw(m_RectangleLog);
		m_RectangleLog.setPosition(230, 480);
		m_Window.draw(m_RectangleLog);

		m_Window.draw(m_TextName);
		m_Window.draw(m_TextPassword);
		m_Window.draw(m_TextLogIn);
		m_Window.draw(m_TextLogUp);
		m_Window.draw(m_TextNameTitle);
		m_Window.draw(m_TextPasswordTitle);

		m_Window.display();
	}

	void LogRender::SetFocus(bool focus) {
		if (focus) {
			m_RectanglePassword.setOutlineThickness(5);
			m_RectangleName.setOutlineThickness(0);
		}
		else {
			m_RectangleName.setOutlineThickness(5);
			m_RectanglePassword.setOutlineThickness(0);
		}
		m_Focus = focus;
	}

	void LogRender::AddLetter(char letter) {
		if (!m_Focus) {
			std::string oldName = m_TextName.getString();
			if (oldName.size() < 10) {
				m_TextName.setString(oldName + letter);
			}
		}
		else {
			if (m_Password.size() < 10) {
				m_Password.push_back(letter);
				m_TextPassword.setString(m_TextPassword.getString()+'*');
			}
		}
	}
	void LogRender::EraseLetter() {
		if (!m_Focus) {
			std::string str(m_TextName.getString());
			if (str.size() > 0) {
				str.resize(str.size() - 1);
			}
			m_TextName.setString(str);
		}
		else {
			if (m_Password.size() > 0) {
				m_Password.resize(m_Password.size() - 1);
			}
			m_TextPassword.setString('*'*m_Password.size());
		}
	}

	std::string LogRender::GetName() {
		return m_TextName.getString();
	}

	std::string LogRender::GetPassword() {
		return m_Password;
	}

	void LogRender::IncorrectLog() {
		m_RectangleName.setOutlineColor(sf::Color::Red);
		m_RectanglePassword.setOutlineColor(sf::Color::Red);
		m_RectangleName.setOutlineThickness(5);
		m_RectanglePassword.setOutlineThickness(5);
		m_TextName.setString("");
		m_TextPassword.setString("");
		m_Password = "";
		sf::Clock clock;
		while (true) {
			Draw();
			if (clock.getElapsedTime().asSeconds() > 3) {
				m_RectangleName.setOutlineColor(sf::Color::Black);
				m_RectanglePassword.setOutlineColor(sf::Color::Black);
				SetFocus(0);
				return;
			}
		}
	}
}