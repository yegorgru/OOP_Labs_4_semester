#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "Render.h"
#include "Singleton.h"

namespace Docking::Client {
	class SignRender : public Render, public Singleton<SignRender>
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
		SignRender(sf::RenderWindow& window);
		sf::RenderWindow& m_Window;
		sf::RectangleShape m_RectangleName;
		sf::RectangleShape m_RectanglePassword;
		sf::RectangleShape m_RectangleSign;

		sf::Text m_TextName;
		sf::Text m_TextPassword;
		sf::Text m_TextSignUp;
		sf::Text m_TextSignIn;
		sf::Text m_TextNameTitle;
		sf::Text m_TextPasswordTitle;

		bool m_Focus;

		std::string m_Password;

		friend class Singleton<SignRender>;
	};
}

