#pragma once

#include <SFML/Graphics.hpp>

#include <string>

namespace Docking::Client {
	class LogRender
	{
	public:
		LogRender(sf::RenderWindow& window);
		sf::RenderWindow& Window();
		void draw();

		void SetFocus(bool focus);
		void AddLetter(char letter);
		void EraseLetter();
		std::string GetName();
		std::string GetPassword();
		void IncorrectLog();
	private:
		sf::RenderWindow& m_Window;
		sf::RectangleShape m_RectangleName;
		sf::RectangleShape m_RectanglePassword;
		sf::RectangleShape m_RectangleLog;

		sf::Text m_TextName;
		sf::Text m_TextPassword;
		sf::Text m_TextLogUp;
		sf::Text m_TextLogIn;
		sf::Text m_TextNameTitle;
		sf::Text m_TextPasswordTitle;

		sf::Font font;

		bool m_Focus;
	};
}

