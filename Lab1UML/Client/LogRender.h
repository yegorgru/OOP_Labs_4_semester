#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "Render.h"
#include "Singleton.h"

namespace Docking::Client {
	class LogRender : public Render, public Singleton<LogRender>
	{
	public:
		sf::RenderWindow& Window() override;
		void Draw() override;

		void SetFocus(bool focus);
		void AddLetter(char letter);
		void EraseLetter();
		std::string GetName();
		std::string GetPassword();
		void IncorrectLog();
	private:
		LogRender(sf::RenderWindow& window);
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

		bool m_Focus;

		std::string m_Password;

		friend class Singleton<LogRender>;
	};
}

