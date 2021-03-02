#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "Player.h"

namespace Docking::Client {
	class LeadersRender
	{
	public:
		LeadersRender(sf::RenderWindow& window);
		sf::RenderWindow& Window();
		void draw();

		void AddLetter(char letter);
		void EraseLetter();
		std::string GetName();
		void IncorrectName();

		void SetPlayer(Player player);
		void AddLeader(const Player& player);
	private:
		sf::RenderWindow& m_Window;
		sf::RectangleShape m_RectangleName;
		sf::RectangleShape m_RectangleFind;

		sf::Text m_TextName;
		sf::Text m_TextFind;
		sf::Text m_TextWins;
		sf::Text m_TextWinsNumber;
		sf::Text m_TextLeaders;

		sf::Font font;

		Player m_Player;
	};
}

